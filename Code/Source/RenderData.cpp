//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/RenderData.h"
#include "Scenes/SceneManager.h"
#include "../Include/General/Container/Queue.h"
#include "../Include/Core/Graphic/RenderData/RendererManager.h"

REFLECT_REGISTER(RenderData) /* NOLINT */

RenderData::RenderData() {
    this->cameraInfo = new_ptr<CameraManager::CameraInfo>();
    this->lightInfo = new_ptr<LightManager::LightInfo>();
}

void RenderData::Invoke() {
    //更新renderer数据
    RendererManager::Invoke();
    this->renderers = RendererManager::renderers;
    //更新相机数据
    CameraManager::Invoke(this->cameraInfo);
    //更新灯光数据
    LightManager::Invoke(this->lightInfo);
}