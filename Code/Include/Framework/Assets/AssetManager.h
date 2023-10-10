//
// Created by Administrator on 2023/9/13.
//

#ifndef CODE_ASSETMANAGER_H
#define CODE_ASSETMANAGER_H


#include <deque>
#include "CustomAsset.h"
#include "AssetLog.h"

class AssetManager {
private:
    static std::unordered_map<std::string, var<CustomAsset>> assetMap;
    static std::deque<std::function<void(std::string&)>> refreshes;
    static var<AssetLog> assetLog;
    static int interval;
public:
    static void Initial();
    static var<CustomAsset> Instance(const std::string& path);
    static bool Instance(const std::string& path, var<CustomAsset>& asset);
    static bool Create(const std::string &path, const std::shared_ptr<CustomAsset>& ca);
//    static void Update();
    static void Refresh();
    static bool RegisterRefresh(std::function<void(std::string&)> call);
    static void Save(const std::shared_ptr<CustomAsset>& ca);
    static void Release();
};


#endif //CODE_ASSETMANAGER_H
