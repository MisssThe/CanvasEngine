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

void Scene::SerializeInDeque(inputArchive &archive) {
    int count;
    archive(count);
    std::string type;
    long long ptr;
    EnableState isEnable;
    AliveState isAlive;
    for (int index = 0; index < count; ++index) {
        archive(ptr, type, isAlive, isEnable);
        auto f = CustomEntity::entityMap.find(ptr);
        var<CustomEntity> ce;
        //正常情况下不会出现component不存在的情况
        if (f != CustomEntity::entityMap.end())
            ce = f->second;
        else {
            ce = safe_cast<CustomEntity>(Reflect::Instance(type));
            CustomEntity::entityMap.insert(std::pair(ptr, ce));
        }
        ce->isAlive = isAlive;
        ce->isEnable = isEnable;
        ce->SerializeIn(archive);
    }
}

void Scene::SerializeInInternal(inputArchive &archive) {
    int count;
    archive(count);
    std::string type;
    long long ptr;
    EnableState isEnable;
    AliveState isAlive;
    std::deque<var<GameObject>> goes;
    for (int index = 0; index < count; ++index) {
        archive(ptr, type, isAlive, isEnable);
        auto f = CustomEntity::entityMap.find(ptr);
        var<CustomEntity> ce;
        if (f != CustomEntity::entityMap.end())
            ce = f->second;
        else {
            ce = safe_cast<CustomEntity>(Reflect::Instance(type));
            ce->SerializeIn(archive);
            CustomEntity::entityMap.insert(std::pair(ptr, ce));
        }
        ce->isAlive = isAlive;
        ce->isEnable = isEnable;
        goes.push_back(safe_cast<GameObject>(ce));
    }
    this->SerializeInDeque(archive);
    this->SerializeInDeque(archive);
    this->SerializeInDeque(archive);
    this->SerializeInDeque(archive);
    this->SerializeInDeque(archive);
    CustomEntity::SerializeFinish();

    for (auto go : goes) {
        this->AddGameObject(go);
    }
}

void Scene::SerializeOutDeque(outputArchive &archive, std::deque<std::shared_ptr<Component>>& que) {
    int count = (int)que.size();
    archive(count);
    for (const auto& q : que) {
        auto ptr = reinterpret_cast<long long>(q.get());
        archive(ptr, q->Type(), q->isAlive, q->isEnable);
        q->SerializeOut(archive);
    }
}

void Scene::SerializeOutInternal(outputArchive &archive) {
    //收集所有game object和component
    //直接用地址作key
    int count = (int)this->gameObjects.size();
    archive(count);
    for (const auto& go : this->gameObjects) {
        auto ptr = reinterpret_cast<long long>(go.get());
        archive(ptr, go->Type(), go->isAlive, go->isEnable);
        go->SerializeOut(archive);
    }
    this->SerializeOutDeque(archive, this->componentInitial);
    this->SerializeOutDeque(archive, this->componentEnable);
    this->SerializeOutDeque(archive, this->componentInvoke);
    this->SerializeOutDeque(archive, this->componentDisable);
    this->SerializeOutDeque(archive, this->componentIdle);

    CustomEntity::SerializeFinish();
}

void Scene::Initial() {
    for (const auto& com: this->componentInitial) {
        com->Initial();
        this->componentEnable.push_back(com);
    }
    this->componentInitial.clear();
}

void Scene::Enable() {
    for (const auto& com: this->componentEnable) {
        if (com->isEnable == EnableTrue) {
            com->Enable();
            this->componentInvoke.push_back(com);
        } else {
            this->componentIdle.push_back(com);
        }
    }
    this->componentEnable.clear();
}

void Scene::Invoke() {
    unsigned int invalidCom = 0;
    for (const auto& com: this->componentInvoke) {
        if (com->isEnable == EnableTrue)
            com->Invoke();
        else if (com->isEnable == EnableFalse) {
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
        if (com->isAlive == AliveFalse)
            this->componentRelease.push_back(com);
        else {
            com->isEnable = EnableNone;
            this->componentIdle.push_back(com);
        }
    }
    this->componentDisable.clear();

    unsigned int invalidCom = 0;
    for (const auto& com: this->componentIdle) {
        if (com->isAlive == AliveState::AliveFalse) {
            this->componentRelease.push_back(com);
            com->isAlive = AliveState::AliveNone;
        }
        else if (com->isEnable == EnableState::EnableTrue) {
            this->componentEnable.push_back(com);
            com->isEnable = EnableState::EnableTrue;
        }
        else if (com->isEnable == EnableState::EnableNone || com->isAlive == AliveState::AliveNone)
            invalidCom++;
    }
    if (invalidCom > (this->componentIdle.size() / 3))
    {
        Deque::ClearUp<var<Component>>(this->componentIdle, [](var<Component>& com) {
            return com->isAlive == AliveFalse || com->isEnable == EnableTrue;
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

void Scene::AddComponent(const std::shared_ptr<GameObject>& go, std::shared_ptr<Component>& com) {
    this->componentInitial.push_back(com);
    go->components.push(com);
}

var<Component> Scene::AddComponent(const std::shared_ptr<GameObject>& go, const std::string com) {
    var<Component> c = safe_cast<Component>(Reflect::Instance(com));
    if (c == nullptr)
        return nullptr;
    this->AddComponent(go, c);
    return c;
}

var<Component> Scene::AddComponent(const std::shared_ptr<GameObject>& go, std::string& com) {
    var<Component> c = safe_cast<Component>(Reflect::Instance(com));
    if (c == nullptr)
        return nullptr;
    this->AddComponent(go, c);
    return c;
}