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
var<CustomPtr> CustomEntity::SerializeInPtr(cereal::BinaryInputArchive &archive) {
    bool isAsset;
    std::string identity;
    archive(isAsset, identity);
    if (isAsset) {
        return AssetManager::Instance(identity);
    } else {
        auto entity = Map::Find(SceneManager::entityMap, identity);
        std::string type;
        archive(type);
        if (entity == nullptr) {
            entity = safe_cast<CustomEntity>(Reflect::Instance(type));
            Map::Insert(SceneManager::entityMap, identity, entity);
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
        archive(safe_cast<CustomEntity>(ptr)->id);
        archive(ptr->Type());
    }
}

bool CustomEntity::IsAsset() {
    return false;
}

CustomEntity::CustomEntity() : id(Cipher::Guid()) {

}
