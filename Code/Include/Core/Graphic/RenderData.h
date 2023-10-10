//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_RENDERDATA_H
#define CODE_RENDERDATA_H


#include "CustomPtr.h"
#include "Core/GraphicCore.h"
#include "RenderData/CameraManager.h"
#include "RenderData/LightManager.h"

class RenderData : public CustomPtr {
public:
    std::string Type() override;
    ~RenderData() override = default;
public:
    RenderData();
    void Invoke();
public:
    var<GraphicCore> core;
    std::queue<std::shared_ptr<Renderer>> renderers;
    var<CameraManager::CameraInfo> cameraInfo;
    var<LightManager::LightInfo> lightInfo;
};


#endif //CODE_RENDERDATA_H
