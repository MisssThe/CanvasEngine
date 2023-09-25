//
// Created by MisThe on 2023/9/19.
//

#include "../Include/Engine/Transform.h"

REFLECT_REGISTER(Transform)

void Transform::Initial() {
    std::cout << this->x << "," << this->y << "," << this->z << std::endl;
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

void Transform::SerializeInInternal(inputArchive &archive) {
    archive(this->x,y,z);
}

void Transform::SerializeOutInternal(outputArchive &archive) {
    archive(this->x,y,z);
}
