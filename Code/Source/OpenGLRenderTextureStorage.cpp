//
// Created by Administrator on 2023/10/17.
//

#include <iostream>
#include "../Include/Core/Graphic/Core/OpenGL/OpenGLRenderTextureStorage.h"
#include "glad/glad.h"
#include "../Include/General/Container/Map.h"

void OpenGLRenderTextureStorage::Release() {
    //释放map
}

var<RenderTexture> OpenGLRenderTextureStorage::CreateRT(unsigned int width, unsigned int height, unsigned int depth, ColorFormat format) {
    unsigned int fbo;
    glGenFramebuffers(1, &fbo);
    // GL_READ_FRAMEBUFFER
    // GL_DRAW_FRAMEBUFFER
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);
    //创建颜色缓冲区
    unsigned int texColorBuffer;
    glGenTextures(1, &texColorBuffer);
    glBindTexture(GL_TEXTURE_2D, texColorBuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texColorBuffer, 0);
    //创建深度缓冲区
    unsigned int rbo;
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    unsigned int depthAndStencil;
    switch (depth) {
        case 24:
            depthAndStencil = GL_DEPTH24_STENCIL8;
            break;
        case 32:
            depthAndStencil = GL_DEPTH32F_STENCIL8;
            break;
        default:
            depthAndStencil = GL_DEPTH24_STENCIL8;
    }
    glRenderbufferStorage(GL_RENDERBUFFER, depthAndStencil, width, height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
        return nullptr;
    }
    //添加rt
    var<RenderTexture> rt = new_ptr<RenderTexture>();
    Map::Insert(this->renderTextureMap, rt,fbo);
    return rt;
}

void OpenGLRenderTextureStorage::DestroyRT(unsigned int fbo) {
    glDeleteFramebuffers(1, &fbo);
}


var<RenderTexture> OpenGLRenderTextureStorage::GetTemporary(RenderTextureDescribe describe) {
    auto find = this->renderTextures.find(describe);
    if (find == this->renderTextures.end())
        return this->CreateRT(describe.width, describe.height, describe.depth, describe.format);
    else {
        this->renderTextures.erase(describe);
        return find->second;
    }
}

var<RenderTexture> OpenGLRenderTextureStorage::GetTemporary(unsigned int width, unsigned int height, unsigned int depth, ColorFormat format) {
    RenderTextureDescribe describe{};
    describe.width = width;
    describe.height = height;
    describe.depth = depth;
    describe.format = format;
    return this->GetTemporary(describe);
}

var<RenderTexture> OpenGLRenderTextureStorage::GetTemporary(unsigned int width, unsigned int height) {
    return this->GetTemporary(width, height, 24);
}

var<RenderTexture> OpenGLRenderTextureStorage::GetTemporary(unsigned int width, unsigned int height, unsigned int depth) {
    return this->GetTemporary(width, height, depth, ColorFormat::RGBA32);
}

void OpenGLRenderTextureStorage::Bind(const var<RenderTexture>& renderTexture) {
    if (renderTexture == nullptr)
        return;
    auto find = this->renderTextureMap.find(renderTexture);
    if (find == renderTextureMap.end())
        return;
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, find->second);
}

void OpenGLRenderTextureStorage::PutTemporary(var<RenderTexture>& renderTexture) {
    if (renderTexture == nullptr)
        return;
    this->renderTextures.insert(std::pair<RenderTextureDescribe, var<RenderTexture>>(renderTexture->describe, renderTexture));
}