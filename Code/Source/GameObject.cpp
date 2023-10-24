//
// Created by Administrator on 2023/9/14.
//

#include "Scenes/GameObject.h"
#include "../Include/General/Container/Queue.h"

REFLECT_REGISTER(GameObject) /* NOLINT */

void GameObject::SerializeInInternal(inputArchive &archive) {
    int count = 0;
    archive(count);
    for (int index = 0; index < count; ++index) {
        auto com = this->SerializeInPtr(archive);
        this->components.push(safe_cast<Component>(com));
    }
}

void GameObject::SerializeOutInternal(outputArchive &archive) {
    int count = (int)components.size();
    archive(count);
    Queue::Iterator<var<Component>>(this->components, [&archive, this](var<Component>& component) {
        auto comPtr = cast<CustomPtr>(component);
        this->SerializeOutPtr(archive, comPtr);
    });
}

bool GameObject::IsGameObject() {
    return true;
}

void GameObject::SetActive(bool flag) {
    this->isEnable = flag? EnableTrue : EnableFalse;
    Queue::IteratorRemove<var<Component>>(this->components, [&flag](var<Component>& com) {
        com->SetActive(flag);
    });
}

void GameObject::Destroy() {
    this->isAlive = AliveFalse;
    Queue::IteratorRemove<var<Component>>(this->components, [](var<Component>& com) {
        com->Destroy();
    });
}
