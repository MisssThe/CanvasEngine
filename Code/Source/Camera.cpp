//
// Created by Administrator on 2023/10/10.
//

#include "../Include/Core/Graphic/RenderData/Components/Camera.h"
#include "../Include/Core/Graphic/RenderData/CameraManager.h"

REFLECT_REGISTER(Camera) /* NOLINT */

void Camera::Initial() {

}

void Camera::Enable() {
    CameraManager::RegisterCamera(shared_from_this());
}

void Camera::Invoke() {

}

void Camera::Disable() {

}

void Camera::Release() {
    CameraManager::RemoveCamera(shared_from_this());
}

void Camera::SerializeInInternal(inputArchive &archive) {

}

void Camera::SerializeOutInternal(outputArchive &archive) {

}