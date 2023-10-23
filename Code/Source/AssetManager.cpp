//
// Created by Administrator on 2023/9/13.
//

#include <fstream>
#include "../Include/Framework/Assets/AssetManager.h"
#include "../Include/General/Container/Map.h"
#include "../Include/General/Tool/Debug.h"
#include "../Include/General/Tool/IO.h"
#include <filesystem>

std::unordered_map<std::string, var<CustomAsset>> AssetManager::assetMap;
std::deque<std::function<void(std::string&)>> AssetManager::refreshes; /* NOLINT */
var<AssetLog> AssetManager::assetLog;
int AssetManager::interval;

bool AssetManager::Instance(const std::string &path, std::shared_ptr<CustomAsset>& asset) {
    if (path.empty() || asset == nullptr || assetMap.find(path) != assetMap.end())
        return false;
    std::ifstream is(path);
    if (!is.is_open())
        return false;
    inputArchive bia(is);
    std::string type;
    bia(type);
    asset->SerializeIn(bia);
    asset->path = path;
    asset->name = IO::FileName(path);
    Map::Insert(assetMap, path, asset);
    return true;
}

var<CustomAsset> AssetManager::Instance(const std::string& path) {
    if (path.empty())
        return nullptr;
    auto ca = assetMap.find(path);
    if (ca != assetMap.end())
        return ca->second;
    std::ifstream is(path, std::ios::binary);
    if (!is.is_open()) {
        Debug::Warn("Error Path [" + path + "]","Asset Manager");
        return nullptr;
    }
    inputArchive bia(is);
    std::string type;
    bia(type);
    var<CustomAsset> cai = nullptr;
    auto temp = Reflect::Instance(type);
    if (temp == nullptr) {
        Debug::Warn("Error Value Type","Asset Manager");
        return nullptr;
    }
    try {
        cai = safe_cast<CustomAsset>(temp);
    } catch (...) {
        //return empty and delete this file
        Debug::Warn("Error Value Type, Cast Failed","Asset Manager");
        return nullptr;
    }
    try {
        cai->SerializeIn(bia);
    } catch(...) {
        Debug::Warn("Asset Has Change","Asset Manager");
    }
    cai->path = path;
    cai->name = IO::FileName(path);
    Map::Insert(assetMap, path, cai);
    is.close();
    return cai;
}

bool AssetManager::Create(const std::string &path, const std::shared_ptr<CustomAsset>& ca) {
    if (ca == nullptr || path.empty())
        return false;
    std::ofstream os(path, std::ios::binary);
    if (!os.is_open())
        return false;
    outputArchive boa(os);
    boa(ca->Type());
    ca->SerializeOut(boa);
    ca->path = path;
    ca->name = IO::FileName(path);
    Map::Insert(assetMap, path, ca);
    os.close();
    return true;
}

void AssetManager::Release() {
    for (const auto &sa: assetMap) {
        Save(sa.second);
    }
    assetMap.clear();
}

void AssetManager::Save(const std::shared_ptr<CustomAsset> &ca) {
    if (ca == nullptr)
        return;
    Create(ca->path, ca);
}

void AssetManager::Refresh() {
    if (interval++ < assetLog->interval)
        return;
    interval = 0;
    //扫描并处理所有改动文件
    for (const auto &file: std::filesystem::recursive_directory_iterator("Assets")) {
        std::string p = file.path().string();
        if (IO::IsDirectory(p))
            continue;
        if (AssetManager::assetLog->Replace(p)) {
            for (const auto &call: refreshes) {
                call(p);
            }
        }
    }
}

bool AssetManager::RegisterRefresh(std::function<void(std::string &)> call) {
    refreshes.push_back(call);
    return true;
}

void AssetManager::Initial() {
    //加载日志文件
    assetLog = safe_cast<AssetLog>(AssetManager::Instance("Assets/Global/AssetLog.al"));
    assetLog->interval = 360;
    AssetManager::interval = assetLog->interval + 1;
    Refresh();
}