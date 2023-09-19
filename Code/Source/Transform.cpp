//
// Created by MisThe on 2023/9/19.
//

#include "../Include/Engine/Transform.h"

REFLECT_REGISTER(Transform)

void Transform::Initial() {

}

void Transform::Enable() {

}

void Transform::Invoke() {
    std::cout << this->x << "," << this->y << "," << this->z << std::endl;
}

void Transform::Disable() {

}

void Transform::Release() {

}

void Transform::SerializeInInternal(cereal::BinaryInputArchive &archive) {

}

void Transform::SerializeOutInternal(cereal::BinaryOutputArchive &archive) {

}
