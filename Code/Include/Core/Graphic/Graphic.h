//
// Created by Administrator on 2023/9/25.
// 外部只能通过Graphic与图形模块进行交互
//

#ifndef CODE_GRAPHIC_H
#define CODE_GRAPHIC_H

#include "Core/GraphicCore.h"
#include "Pipeline/GraphicPipeline.h"

enum GraphicType
{
    OpenGL, Metal, DXD, Vulkan
};

enum PipelineType
{
    Forward
};

class Renderer;

class Graphic {
public:
    static void Initial();
    static void Invoke();
    static void Release();
private:
    static var<GraphicCore> core;
    static var<GraphicPipeline> pipeline;
    static var<RenderData> renderData;
};


#endif //CODE_GRAPHIC_H
