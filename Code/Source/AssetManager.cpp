//
// Created by Administrator on 2023/9/13.
//

#include <fstream>
#include "../Include/Framework/Assets/AssetManager.h"
#include "../Include/General/Map.h"
#include "../Include/General/Debug.h"
#include <filesystem>

std::unordered_map<std::string, var<CustomAsset>> AssetManager::assetMap;
std::deque<std::function<void(std::string&)>> AssetManager::refreshes; /* NOLINT */
var<AssetLog> AssetManager::assetLog;

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
    asset->name = "!";
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
        Debug::Warm("Error Path [" + path + "]","Asset Manager");
        return nullptr;
    }
    inputArchive bia(is);
    std::string type;
    bia(type);
    var<CustomAsset> cai = nullptr;
    auto temp = Reflect::Instance(type);
    if (temp == nullptr) {
        Debug::Warm("Error Value Type","Asset Manager");
        return nullptr;
    }
    try {
        cai = safe_cast<CustomAsset>(temp);
    } catch (...) {
        //return empty and delete this file
        Debug::Warm("Error Value Type, Cast Failed","Asset Manager");
        return nullptr;
    }
    try {
        cai->SerializeIn(bia);
    } catch(...) {
        Debug::Warm("Asset Has Change","Asset Manager");
    }
    cai->path = path;
    cai->name = "!";
    Map::Insert(assetMap, path, cai);
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
    ca->name = "!";
    Map::Insert(assetMap, path, ca);
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
    //扫描并处理所有改动文件
    for (const auto & file : std::filesystem::recursive_directory_iterator("Assets"))
    {
        std::string p = file.path().string();
        if (AssetManager::assetLog->Replace(p)) {
            for (auto call : refreshes) {
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
    Refresh();
}