//
// Created by Administrator on 2023/10/10.
//

#ifndef CODE_RENDERERMANAGER_H
#define CODE_RENDERERMANAGER_H

#include <queue>
#include "Components/Renderer.h"

class RendererManager {
public:
    static void Invoke();
    static void RegisterRenderer(var<Renderer> renderer);
public:
    static std::queue<var<Renderer>> renderers;
};


#endif //CODE_RENDERERMANAGER_H
