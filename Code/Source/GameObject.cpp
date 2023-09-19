//
// Created by Administrator on 2023/9/14.
//

#include "Scenes/GameObject.h"
#include "../Include/General/Queue.h"

REFLECT_REGISTER(GameObject) /* NOLINT */

void GameObject::SerializeInInternal(cereal::BinaryInputArchive &archive) {
    int count = 0;
    archive(this->name, count);
    for (int index = 0; index < count; ++index) {
        auto com = this->SerializeInPtr(archive);
        this->components.push(safe_cast<Component>(com));
    }
}

void GameObject::SerializeOutInternal(cereal::BinaryOutputArchive &archive) {
    int count = this->components.size();
    archive(this->name, count);
    Queue::Iterator<var<Component>>(this->components, [&archive, this](var<Component>& component) {
        auto comPtr = cast<CustomPtr>(component);
        this->SerializeOutPtr(archive, comPtr);
    });
}

bool GameObject::IsGameObject() {
    return true;
}

var<Component> GameObject::AddComponent(const std::string& com) {
    auto c = Reflect::Instance(com);
    if (c == nullptr)
        return nullptr;
    var<Component> ct = safe_cast<Component>(c);
    this->components.push(ct);
    return ct;
}
