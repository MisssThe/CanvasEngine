//
// Created by Administrator on 2023/9/14.
//

#include "Scenes/GameObject.h"

REFLECT_REGISTER(GameObject) /* NOLINT */

void GameObject::SerializeInInternal(cereal::BinaryInputArchive &archive) {

}

void GameObject::SerializeOutInternal(cereal::BinaryOutputArchive &archive) {

}

bool GameObject::IsGameObject() {
    return true;
}