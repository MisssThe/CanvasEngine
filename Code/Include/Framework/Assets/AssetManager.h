//
// Created by Administrator on 2023/9/13.
//

#ifndef CODE_ASSETMANAGER_H
#define CODE_ASSETMANAGER_H


#include "CustomAsset.h"

class AssetManager {
private:
    static std::unordered_map<std::string, var<CustomAsset>> assetMap;
public:
    static var<CustomAsset> Instance(const std::string& path);
    static bool Create(const std::string &path, const std::shared_ptr<CustomAsset>& ca);
    static void Update();
    static void Save(const std::shared_ptr<CustomAsset>& ca);
    static void Release();
};


#endif //CODE_ASSETMANAGER_H
