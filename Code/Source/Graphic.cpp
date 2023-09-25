//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Graphic.h"
#include "../Include/Core/Graphic/Core/GraphicOpenGLCore.h"
#include "GlobalSetting.h"

var<GraphicCore> Graphic::core;
std::vector<var<Renderer>> Graphic::renderers;

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
    }
}

void Graphic::Invoke() {
    //整理render数据
    //调用render pipeline
    //释放所有数据
    renderers.clear();
}

void Graphic::Release() {

}

void Graphic::Register(std::shared_ptr<Renderer> renderer) {
    renderers.push_back(renderer);
}
