//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Graphic.h"
#include "../Include/Core/Graphic/Core/OpenGL/GraphicOpenGLCore.h"
#include "GlobalSetting.h"
#include "../Include/Core/Graphic/Pipeline/Pipeline/ForwardPipeline.h"
#include "../Include/Engine.h"

var<GraphicCore> Graphic::core;
var<GraphicPipeline> Graphic::pipeline;
var<RenderData> Graphic::renderData;

void Graphic::Initial() {
    switch (GlobalSetting::graphicType) {
        case OpenGL:
            core = cast<GraphicCore>(new_ptr<GraphicOpenGLCore>());
            break;
        case Metal:
            break;
        case DXD:
            break;
        case Vulkan:
            break;
        default:
            core = cast<GraphicCore>(new_ptr<GraphicOpenGLCore>());
    }
    switch (GlobalSetting::pipelineType) {
        case Forward:
            pipeline = cast<GraphicPipeline>(new_ptr<ForwardPipeline>());
            break;
        default:
            pipeline = cast<GraphicPipeline>(new_ptr<ForwardPipeline>());
    }
    Engine::RegisterClose([]() {
        return core->IsExist();
    });
    renderData = new_ptr<RenderData>();
}

void Graphic::Invoke() {
    //整理render数据
    renderData->core = core;
    renderData->Invoke();
    //调用render pipeline
    pipeline->Invoke(renderData);
}

void Graphic::Release() {
    CameraManager::Release();
    LightManager::Release();
}