//
// Created by Administrator on 2023/9/25.
// 外部只能通过Graphic与图形模块进行交互
//

#ifndef CODE_GRAPHIC_H
#define CODE_GRAPHIC_H

#include "Core/GraphicCore.h"

enum GraphicType
{
    OpenGL, Metal, DXD, Vulkan
};

class Renderer;

class Graphic {
public:
    static void Initial();
    static void Invoke();
    static void Release();
    static void Register(var<Renderer> renderer);
private:
    static var<GraphicCore> core;
    static std::vector<var<Renderer>> renderers;
};


#endif //CODE_GRAPHIC_H
