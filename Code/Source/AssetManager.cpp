//
// Created by Administrator on 2023/9/13.
//

#include <fstream>
#include "../Include/Framework/Assets/AssetManager.h"
#include "../Include/General/Map.h"

std::unordered_map<std::string, var<CustomAsset>> AssetManager::assetMap;

bool AssetManager::Instance(const std::string &path, std::shared_ptr<CustomAsset>& asset) {
    if (path.empty() || asset == nullptr || assetMap.find(path) != nullptr)
        return false;
    std::ifstream is(path);
    if (!is.is_open())
        return false;
    cereal::BinaryInputArchive bia(is);
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
    std::ifstream is(path);
    if (!is.is_open())
        return nullptr;
    cereal::BinaryInputArchive bia(is);
    std::string type;
    bia(type);
    var<CustomAsset> cai = nullptr;
    auto temp = Reflect::Instance(type);
    if (temp == nullptr)
        return nullptr;
    try {
        cai = safe_cast<CustomAsset>(temp);
    } catch (...) {
        //return empty and delete this file
        return nullptr;
    }
    cai->SerializeIn(bia);
    cai->path = path;
    cai->name = "!";
    Map::Insert(assetMap, path, cai);
    return cai;
}

bool AssetManager::Create(const std::string &path, const std::shared_ptr<CustomAsset>& ca) {
    if (ca == nullptr || path.empty())
        return false;
    std::ofstream os(path);
    if (!os.is_open())
        return false;
    cereal::BinaryOutputArchive boa(os);
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