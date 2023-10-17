//
// Created by Administrator on 2023/10/17.
//

#include "../Include/Core/Graphic/Core/OpenGL/OpenGLRenderTextureStorage.h"
#include "glad/glad.h"

void OpenGLRenderTextureStorage::Release() {
    //释放map
}

unsigned int OpenGLRenderTextureStorage::CreateRT(unsigned int width, unsigned int height, unsigned int depth, OpenGLRenderTextureStorage::ColorFormat format) {
    unsigned int fbo;
    glGenFramebuffers(1, &fbo);
    // GL_READ_FRAMEBUFFER
    // GL_DRAW_FRAMEBUFFER
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    //创建颜色缓冲区
    //创建深度缓冲区
    return 1;
//    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)
//        return;
}

void OpenGLRenderTextureStorage::DestroyRT(unsigned int fbo) {
    glDeleteFramebuffers(1, &fbo);
}

var<RenderTexture> OpenGLRenderTextureStorage::GetTemporary(unsigned int width, unsigned int height, unsigned int depth,OpenGLRenderTextureStorage::ColorFormat format) {
    var<RenderTexture> result = nullptr;
    auto f1 = this->renderTextureMap.find(width);
    if (f1 != this->renderTextureMap.end()) {
        auto f2 = f1->second.find(height);
        if (f2 != f1->second.end()) {
            auto f3 = f2->second.find(depth);
            if (f3 != f2->second.end()) {
                auto f4 = f3->second.find(format);
                if (f4 != f3->second.end())
                    result = f4->second;
            }
        }
    }
    if (result == nullptr)
        return result;
    else {
        CreateRT(width, height, depth, format);
    }
    return std::shared_ptr<RenderTexture>();
}

var<RenderTexture> OpenGLRenderTextureStorage::GetTemporary(unsigned int width, unsigned int height) {
    return this->GetTemporary(width, height, 24);
}

var<RenderTexture> OpenGLRenderTextureStorage::GetTemporary(unsigned int width, unsigned int height, unsigned int depth) {
    return this->GetTemporary(width, height, depth, ColorFormat::RGBA32);
}

void OpenGLRenderTextureStorage::Bind(std::shared_ptr<RenderTexture> renderTexture) {

}

void OpenGLRenderTextureStorage::PutTemporary(std::shared_ptr<RenderTexture> renderTexture) {

}
