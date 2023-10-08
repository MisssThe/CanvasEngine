//
// Created by MisThe on 2023/9/19.
//

#include "../Include/Core/Graphic/Renderer.h"
#include "../Include/Core/Graphic/Graphic.h"

REFLECT_REGISTER(Renderer)

void Renderer::Initial() {

}

void Renderer::Enable() {
    Graphic::Register(shared_from_this());
}

void Renderer::Invoke() {

}

void Renderer::Disable() {
//    Graphic::Register(var<Renderer>(this));
}

void Renderer::Release() {

}

void Renderer::SerializeInInternal(inputArchive &archive) {

}

void Renderer::SerializeOutInternal(outputArchive &archive) {

}
