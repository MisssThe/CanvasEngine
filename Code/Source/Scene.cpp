//
// Created by Insomnia on 2023/9/14.
//

#include "Scenes/Scene.h"

#include <utility>
#include "Scenes/GameObject.h"
#include "cereal/types/string.hpp"
#include "../Include/General/Deque.h"
#include "../Include/General/Map.h"
#include "../Include/General/Queue.h"

REFLECT_REGISTER(Scene) /* NOLINT */

void Scene::SerializeInInternal(cereal::BinaryInputArchive &archive) {
    int count;
    archive(count);
    std::string type;
    std::deque<var<GameObject>> goes;
    Cipher::GUID guid;
    for (int index = 0; index < count; ++index) {
        archive(guid, type);
        auto entity = CustomEntity::entityMap[guid];
        if (entity == nullptr) {
            entity = safe_cast<CustomEntity>(Reflect::Instance(type));
            CustomEntity::entityMap.insert(std::pair(guid,entity));
        }
        entity->SerializeIn(archive);
        if (entity->IsGameObject())
            goes.push_back(safe_cast<GameObject>(entity));
    }
    for (auto go : goes) {
        this->AddGameObject(go);
    }
    CustomEntity::SerializeFinish();
}

void Scene::SerializeOutInternal(cereal::BinaryOutputArchive &archive) {
    int count = (int)this->gameObjects.size();
    archive(count);
    for (const auto& go : this->gameObjects) {
        archive(go->guid, go->Type());
        go->SerializeOut(archive);
    }
    CustomEntity::SerializeFinish();
}

void Scene::Initial() {
    for (const auto& com: this->componentInitial) {
        com->Enable();
        this->componentEnable.push_back(com);
    }
    this->componentInitial.clear();
}

void Scene::Enable() {
    for (const auto& com: this->componentEnable) {
        if (com->isEnable == EnableTrue)
            com->Enable();
        this->componentInvoke.push_back(com);
    }
    this->componentEnable.clear();
}

void Scene::Invoke() {
    unsigned int invalidCom = 0;
    for (const auto& com: this->componentInvoke) {
        if (com->isAlive)
            com->Invoke();
        else if (com->isAlive == AliveState::AliveFalse) {
            this->componentDisable.push_back(com);
        } else
            invalidCom++;
    }
    //移动元素到无效元素位置
    if (invalidCom > (this->componentInvoke.size() / 3)) {
        Deque::ClearUp<var<Component>>(this->componentInvoke, [](var<Component> &com) {
            return com->isAlive == AliveNone || com->isEnable == EnableNone;
        });
    }
}

void Scene::Disable() {
    for (const auto& com: this->componentDisable) {
        com->Disable();
        this->componentIdle.push_back(com);
    }
    this->componentDisable.clear();

    unsigned int invalidCom = 0;
    for (const auto& com: this->componentIdle) {
        if (com->isAlive == AliveState::AliveFalse) {
            this->componentRelease.push_back(com);
            com->isAlive = AliveState::AliveNone;
        }
        else if (com->isEnable == EnableState::EnableFalse) {
            this->componentEnable.push_back(com);
            com->isEnable = EnableState::EnableNone;
        }
        else if (com->isEnable == EnableState::EnableNone || com->isAlive == AliveState::AliveNone)
            invalidCom++;
    }
    if (invalidCom > (this->componentIdle.size() / 3))
    {
        Deque::ClearUp<var<Component>>(this->componentIdle, [](var<Component>& com) {
            return com->isAlive == AliveNone || com->isEnable == EnableNone;
        });
    }
}

void Scene::Release() {
    for (const auto& com: this->componentRelease) {
        com->Release();
    }
    this->componentRelease.clear();
}

void Scene::AddGameObject(std::shared_ptr<GameObject>& go) {
    this->gameObjects.push_back(go);
    Queue::Iterator<var<Component>>(go->components, [this](var<Component>& com) {
        this->componentInitial.push_back(com);
    });
}

var<GameObject> Scene::AddGameObject(std::string name) {
    auto go = new_ptr<GameObject>();
    go->name = std::move(name);
    this->AddGameObject(go);
    return go;
}

void Scene::AddComponent(std::shared_ptr<GameObject>& go, std::shared_ptr<Component>& com) {
    this->componentInitial.push_back(com);
}

void Scene::AddComponent(std::shared_ptr<GameObject> go, std::string& com) {
    var<Component> c = safe_cast<Component>(Reflect::Instance(com));
    if (c == nullptr)
        return;
    this->AddComponent(go, c);
}
