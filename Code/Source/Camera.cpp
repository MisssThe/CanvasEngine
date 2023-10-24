//
// Created by Administrator on 2023/10/10.
//

#include "../Include/Core/Graphic/RenderData/Components/Camera.h"
#include "../Include/Core/Graphic/RenderData/CameraManager.h"
#include "StaticInfo.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

REFLECT_REGISTER(Camera) /* NOLINT */

void Camera::Initial() {

}

void Camera::Enable() {
    CameraManager::RegisterCamera(shared_from_this());
}

void Camera::Invoke() {
    //根据相机数据刷新矩阵信息
    this->UpdateInfo();
}

void Camera::Disable() {
    CameraManager::RemoveCamera(shared_from_this());
}

void Camera::Release() {

}

void Camera::SerializeInInternal(inputArchive &archive) {
    archive(projectionMode, clipPlane, viewPort);
}

void Camera::SerializeOutInternal(outputArchive &archive) {
    archive(projectionMode, clipPlane, viewPort);
}

void Camera::UpdateInfo() {
    //刷新投影矩阵
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float) StaticInfo::windowWidth / (float) StaticInfo::windowHeight, 0.1f, 100.0f);
    //刷新视角矩阵
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
}
