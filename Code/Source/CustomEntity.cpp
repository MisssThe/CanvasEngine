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
GuidMap<var<CustomEntity>> CustomEntity::entityMap;   //只用于初始的序列化

var<CustomPtr> CustomEntity::SerializeInPtr(cereal::BinaryInputArchive &archive) {
    bool isAsset;
    archive(isAsset);
    if (isAsset) {
        std::string identity;
        archive(identity);
        return AssetManager::Instance(identity);
    } else {
        Cipher::GUID id;
        std::string type;
        archive(id, type);
        auto mf = entityMap.Find(id);
        var<CustomEntity> entity;
        if (mf == nullptr) {
            entity = safe_cast<CustomEntity>(Reflect::Instance(type));
            entityMap.Insert(id,entity);
        } else {
            entity = mf;
        }
        return entity;
    }
}

void CustomEntity::SerializeOutPtr(cereal::BinaryOutputArchive &archive, std::shared_ptr<CustomPtr>& ptr) {
    bool isAsset = ptr->IsAsset();
    archive(isAsset);
    if (isAsset)
        archive(safe_cast<CustomAsset>(ptr)->path);
    else {
        archive(safe_cast<CustomEntity>(ptr)->guid,ptr->Type());

    }
}

bool CustomEntity::IsAsset() {
    return false;
}

CustomEntity::CustomEntity() : guid(Cipher::Guid()) {
    this->isEnable = EnableTrue;
    this->isAlive = AliveTrue;
}

void CustomEntity::SerializeFinish() {

}
