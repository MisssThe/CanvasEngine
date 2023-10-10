//
// Created by Administrator on 2023/9/15.
//

#include "Scenes/Component.h"

//REFLECT_REGISTER(Component) /* NOLINT */
bool Component::IsGameObject() {
    return false;
}

void Component::SetActive(bool flag) {
    this->isEnable = flag? EnableTrue : EnableFalse;
}

void Component::Destroy() {
    this->isAlive = AliveFalse;
}

void Component::Initial() {
    //ignore
}

void Component::Enable() {
    //ignore
}

void Component::Invoke() {
    //ignore
}

void Component::Disable() {
    //ignore
}

void Component::Release() {
    //ignore
}
