//
// Created by Administrator on 2023/10/10.
//

#include "../Include/Core/Graphic/RenderData/RendererManager.h"
#include "../Include/General/Queue.h"

std::queue<var<Renderer>> RendererManager::renderers;

void RendererManager::Invoke() {
    Queue::IteratorRemoveBool<var<Renderer>>(renderers, [](var<Renderer>& renderer){
        return renderer->isEnable == EnableTrue;
    });
}

void RendererManager::RegisterRenderer(std::shared_ptr<Renderer> renderer) {
    if (renderer == nullptr)
        return;
    renderers.push(renderer);
}
