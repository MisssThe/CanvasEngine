//
// Created by Administrator on 2023/10/13.
//

#include "../Include/Core/Graphic/Core/OpenGL//OpenGLShaderStorage.h"
#include "glad/glad.h"
#include "../Include/General/Container/Map.h"

void OpenGLShaderStorage::Bind(std::shared_ptr<ShaderAsset> shader) {
    unsigned int program;
    if (this->shaders.find(shader) == this->shaders.end())
        program = CompileShader(shader);
    else
        program = this->shaders[shader];
    glUseProgram(program);
}

void OpenGLShaderStorage::Release() {

}

unsigned int OpenGLShaderStorage::CompileShader(std::shared_ptr<ShaderAsset> shader) {
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderSource = shader->vertCode.c_str();
    const char* fragmentShaderSource = shader->fragCode.c_str();
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    //查找数据ID
    glUseProgram(shaderProgram);
    for (const auto& info : shader->properties) {
        Map::Insert<std::string, int>(shader->propertiesID, info.first, glGetUniformLocation(shaderProgram, info.first.c_str()));
    }
    Map::Insert<var<ShaderAsset>, unsigned int>(this->shaders, shader, shaderProgram);
    return shaderProgram;
}

void OpenGLShaderStorage::SetInfo(const std::shared_ptr<MaterialAsset>& info) {
    //============== 设置深度测试 ==============
    switch (info->depthTest) {
        case MaterialAsset::LEqual:
            glDepthFunc(GL_LEQUAL);
            break;
        default:
            glDepthFunc(GL_LEQUAL);
    }

    //============== 设置深度写入 ==============
    if (info->depthWrite)
        glDepthMask(GL_TRUE);
    else
        glDepthMask(GL_TRUE);

    //============== 设置混合模式 ==============
    switch (info->blend) {
        case MaterialAsset::Opaque:
            glBlendFunc(GL_ONE, GL_ZERO);
            break;
        case MaterialAsset::Transparent:
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            break;
    }
    //============== 设置剔除模式 ==============
    switch (info->cull) {
        case MaterialAsset::Front:
            glCullFace(GL_BACK);
            break;
        case MaterialAsset::Back:
            glCullFace(GL_FRONT);
            break;
        case MaterialAsset::Both:
            glDisable(GL_FRONT_AND_BACK);
            break;
    }
    //============== 设置具体属性 ==============
    int textureIndex = 0;
    for (const auto& p : info->shader->properties) {
        auto f = info->properties.find(p.first);
        auto c= info->properties["normalTex"];
        if (f == info->properties.end())
            continue;
        if (f->second.flag != p.second)
            continue;
        int location = info->shader->propertiesID[p.first];
        switch (p.second) {
            case ShaderAsset::Vec1:
                glUniform1f(location, f->second.info[0]);
                break;
            case ShaderAsset::Vec2:
                glUniform2f(location, f->second.info[0], f->second.info[1]);
                break;
            case ShaderAsset::Vec3:
                glUniform3f(location, f->second.info[0], f->second.info[1],  f->second.info[2]);
                break;
            case ShaderAsset::Vec4:
                glUniform4f(location, f->second.info[0], f->second.info[1],  f->second.info[2],  f->second.info[3]);
                break;
            case ShaderAsset::Texture2D:
                glUniform1i(location, textureIndex);
                auto a = f->second;
                auto b = f->first;
                this->textureStorage->Bind(f->second.texture, textureIndex++);
                break;
        }
    }
}

OpenGLShaderStorage::OpenGLShaderStorage() {
    this->textureStorage = new_ptr<OpenGLTextureStorage>();
}
