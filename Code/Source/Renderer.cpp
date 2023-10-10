//
// Created by MisThe on 2023/9/19.
//

#include "../Include/Core/Graphic/RenderData/Components/Renderer.h"
#include "../Include/Core/Graphic/RenderData/RendererManager.h"

REFLECT_REGISTER(Renderer)

void Renderer::Initial() {

}

void Renderer::Enable() {
    RendererManager::RegisterRenderer(shared_from_this());
}

void Renderer::Invoke() {

}

void Renderer::Disable() {

}

void Renderer::Release() {

}

void Renderer::SerializeInInternal(inputArchive &archive) {
    this->mesh = safe_cast<MeshAsset>(SerializeInPtr(archive));
    this->material = safe_cast<MaterialAsset>(SerializeInPtr(archive));
}

void Renderer::SerializeOutInternal(outputArchive &archive) {
    SerializeOutPtr(archive, this->mesh);
    SerializeOutPtr(archive, this->material);
}
