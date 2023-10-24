//
// Created by Administrator on 2023/10/17.
//

#include "../Include/Core/Graphic/Core/OpenGL/OpenGLTextureStorage.h"
#include "glad/glad.h"
#include "../Include/General/Container/Map.h"
#define STB_IMAGE_IMPLEMENTATION
#include "custom_image.h"
#include "../Include/General/Tool/Debug.h"

void OpenGLTextureStorage::Bind(std::shared_ptr<TextureAsset>& textureAsset, int index) {
    auto find = this->textureMap.find(textureAsset);
    unsigned int texture = -1;
    if (find == this->textureMap.end())
        texture = this->CompileTexture(textureAsset);
    else
        texture = find->second;
    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D, texture);
}

unsigned int OpenGLTextureStorage::CompileTexture(std::shared_ptr<TextureAsset> &textureAsset) {
    unsigned int texture;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    //设置环绕
    int type = -1;
    switch (textureAsset->repeat) {
        case TextureAsset::Repeat:
            type = GL_REPEAT;
            break;
        case TextureAsset::Mirror:
            type = GL_MIRRORED_REPEAT;
            break;
        case TextureAsset::Clamp:
            type = GL_CLAMP_TO_EDGE;
            break;
        case TextureAsset::ClampWithColor:
            type = GL_CLAMP_TO_BORDER;
            break;
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, type);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, type);
    //过滤方式
    switch (textureAsset->filter) {
        case TextureAsset::Point:
            type = GL_NEAREST;
            break;
        case TextureAsset::Linear:
            type = GL_LINEAR;
            break;
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, type);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, type);
    //加载并生成纹理
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(textureAsset->texturePath.c_str(), &width, &height, &nrChannels, 0);

    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        Debug::Warn("Failed load texture [" + textureAsset->path + "]", "Compile OpenGL Texture");
        std::cout << "Failed to load texture" << std::endl;
        return -1;
    }
    stbi_image_free(data);

    Map::Insert<var<TextureAsset>, unsigned int>(this->textureMap, textureAsset, texture);
    return texture;
}
