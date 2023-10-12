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
