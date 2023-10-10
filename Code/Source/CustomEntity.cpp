//
// Created by Administrator on 2023/9/14.
//

#include "Scenes/CustomEntity.h"
#include "Assets/CustomAsset.h"
#include "Scenes/SceneManager.h"
#include "Assets/AssetManager.h"
#include "../Include/General/Map.h"
#include "../Include/General/Cipher.h"

//REFLECT_REGISTER(CustomEntity)
std::unordered_map<long long, var<CustomEntity> > CustomEntity::entityMap;   //只用于初始的序列化

var<CustomPtr> CustomEntity::SerializeInPtr(inputArchive &archive) {
    bool isAsset;
    archive(isAsset);
    if (isAsset) {
        std::string identity;
        archive(identity);
        return AssetManager::Instance(identity);
    } else {
        long long id;
        std::string type;
        archive(id, type);
        auto mf = entityMap.find(id);
        var<CustomEntity> entity;
        if (mf == entityMap.end()) {
            entity = safe_cast<CustomEntity>(Reflect::Instance(type));
            entityMap.insert(std::pair( id,entity));
        } else {
            entity = mf->second;
        }
        return entity;
    }
}

void CustomEntity::SerializeOutPtr(outputArchive &archive, std::shared_ptr<CustomPtr> ptr) {
    bool isAsset = ptr->IsAsset();
    archive(isAsset);
    if (isAsset)
        archive(safe_cast<CustomAsset>(ptr)->path);
    else {
        auto p = reinterpret_cast<long long>(ptr.get());
        archive(p, ptr->Type());
    }
}

CustomEntity::CustomEntity() {
    this->isEnable = EnableTrue;
    this->isAlive = AliveTrue;
}

void CustomEntity::SerializeFinish() {
    CustomEntity::entityMap.clear();
}

bool CustomEntity::IsAsset() {
    return false;
}
