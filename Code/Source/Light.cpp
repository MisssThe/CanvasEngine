//
// Created by Administrator on 2023/10/10.
//

#include "../Include/Core/Graphic/RenderData/Components/Light.h"
#include "../Include/Core/Graphic/RenderData/LightManager.h"

REFLECT_REGISTER(Light) /* NOLINT */

void Light::Initial() {

}

void Light::Enable() {
    LightManager::RegisterLight(shared_from_this());
}

void Light::Invoke() {

}

void Light::Disable() {

}

void Light::Release() {
    LightManager::RemoveLight(shared_from_this());
}

void Light::SerializeInInternal(inputArchive &archive) {

}

void Light::SerializeOutInternal(outputArchive &archive) {

}