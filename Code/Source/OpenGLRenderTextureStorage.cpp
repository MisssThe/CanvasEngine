//
// Created by Administrator on 2023/10/17.
//

#include <iostream>
#include "../Include/Core/Graphic/Core/OpenGL/OpenGLRenderTextureStorage.h"
#include "glad/glad.h"
#include "../Include/General/Container/Map.h"
#include "../Include/General/Tool/Debug.h"

void OpenGLRenderTextureStorage::Release() {
    //释放map
}

var<RenderTexture> OpenGLRenderTextureStorage::CreateRT(const RenderTextureDescribe &describe) {
    GLuint buffer;
    glGenFramebuffers(1, &buffer);
    glBindFramebuffer(GL_FRAMEBUFFER, buffer);

    int count = (int) describe.formats.size();
    unsigned int attachments[count];
    for (int i = 0; i < count; ++i) {
        unsigned int color;
        glGenTextures(1, &color);
        glBindTexture(GL_TEXTURE_2D, color);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (int) describe.width, (int) describe.height, 0, GL_RGBA, GL_FLOAT, nullptr);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, color, 0);
        attachments[i] = GL_COLOR_ATTACHMENT0 + i;
    }
    glDrawBuffers(count, attachments);

    unsigned int rbo;
    glGenRenderbuffers(1, &rbo);
    glBindRenderbuffer(GL_RENDERBUFFER, rbo);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, describe.width, describe.height);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);

    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        Debug::Error("Create Render Texture", "Create Failed");
        return nullptr;
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    var<RenderTexture> rt = new_ptr<RenderTexture>();
    rt->describe = describe;
    Map::Insert(this->renderTextureMap, rt, buffer);
    return rt;
}

void OpenGLRenderTextureStorage::DestroyRT(unsigned int fbo) {
    glDeleteFramebuffers(1, &fbo);
}


var<RenderTexture> OpenGLRenderTextureStorage::GetTemporary(RenderTextureDescribe describe) {
    auto find = this->renderTextures.find(describe);
    if (find == this->renderTextures.end())
        return this->CreateRT(describe);
    else {
        this->renderTextures.erase(describe);
        return find->second;
    }
}

void OpenGLRenderTextureStorage::Bind(const var<RenderTexture>& renderTexture) {
    if (renderTexture == nullptr) {
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
        return;
    }
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