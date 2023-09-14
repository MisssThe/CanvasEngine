//
// Created by Insomnia on 2023/9/14.
//

#include "Scenes/Scene.h"
#include "../Include/General/Queue.h"
#include "Scenes/SceneManager.h"
#include "../Include/General/Map.h"

REFLECT_REGISTER(Scene) /* NOLINT */

void Scene::SerializeInInternal(cereal::BinaryInputArchive &archive) {
    SceneManager::entityMap.clear();
    unsigned int count;
    archive(count);
    std::string guid, type;
    for (unsigned int index = 0; index < count; ++index) {
        archive(guid, type);
        auto entity = SceneManager::entityMap[guid];
        if (entity == nullptr) {
            entity = safe_cast<CustomEntity>(Reflect::Instance(type));
            Map::Insert(SceneManager::entityMap, guid, entity);
        }
        entity->SerializeIn(archive);
        this->entitiesInitial.push(entity);
    }
}

void Scene::SerializeOutInternal(cereal::BinaryOutputArchive &archive) {
    SceneManager::entityMap.clear();
    Queue::Iterator<var<CustomEntity>>(entitiesInitial, [](var<CustomEntity>& entity) { Map::Insert(SceneManager::entityMap, entity->id, entity); });
    Queue::Iterator<var<CustomEntity>>(entitiesEnable, [](var<CustomEntity>& entity) { Map::Insert(SceneManager::entityMap, entity->id, entity); });
    Queue::Iterator<var<CustomEntity>>(entitiesInvoke, [](var<CustomEntity>& entity) { Map::Insert(SceneManager::entityMap, entity->id, entity); });
    Queue::Iterator<var<CustomEntity>>(entitiesDisable, [](var<CustomEntity>& entity) { Map::Insert(SceneManager::entityMap, entity->id, entity); });
    Queue::Iterator<var<CustomEntity>>(entitiesRelease, [](var<CustomEntity>& entity) { Map::Insert(SceneManager::entityMap, entity->id, entity); });

    archive(SceneManager::entityMap.size());
    for (auto entity : SceneManager::entityMap) {
        archive(entity.first, entity.second->Type());
    }
        //添加所有entities到map中
//    Queue::Iterator<var<CustomEntity>>(entitiesInitial, [this](var<CustomEntity>& entity) {
//
//    });
}

void Scene::Initial() {
    Queue::IteratorRemove<var<CustomEntity>>(entitiesInitial, [this](var<CustomEntity>& entity) {
        entity->Initial();
        entitiesEnable.push(entity);
    });
};

void Scene::Enable() {
    Queue::IteratorRemove<var<CustomEntity>>(entitiesInitial, [this](var<CustomEntity>& entity) {
        entity->Enable();
        entitiesInvoke.push(entity);
    });
}

void Scene::Invoke() {
    Queue::IteratorRemoveBool<var<CustomEntity>>(entitiesInvoke, [this](var<CustomEntity>& entity) {
        entity->Invoke();
        if (entity->isEnable)
            return true;
        else {
            entitiesDisable.push(entity);
            return false;
        }
        return true;
    });
}

void Scene::Disable() {
    Queue::IteratorRemove<var<CustomEntity>>(entitiesInitial, [this](var<CustomEntity>& entity) {
        entity->Disable();
        entitiesIdle.push(entity);
    });
    Queue::IteratorRemoveBool<var<CustomEntity>>(entitiesInitial, [this](var<CustomEntity>& entity) {
        if (entity->isEnable)
            entitiesInvoke.push(entity);
        else if (entity->isAlive)
            entitiesRelease.push(entity);
        else
            return true;
        return false;
    });
}

void Scene::Release() {
    Queue::IteratorRemove<var<CustomEntity>>(entitiesRelease, [](var<CustomEntity>& entity) { entity->Release(); });
}