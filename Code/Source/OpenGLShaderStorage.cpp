//
// Created by Administrator on 2023/10/13.
//

#include "../Include/Core/Graphic/Core/OpenGL//OpenGLShaderStorage.h"
#include "glad/glad.h"
#include "../Include/General/Map.h"

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
    Map::Insert<var<ShaderAsset>, unsigned int>(this->shaders, shader, shaderProgram);
    return shaderProgram;
}

void OpenGLShaderStorage::SetInfo(std::shared_ptr<MaterialAsset> info) {
    if (info->depthTest) {
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
    } else
        glDisable(GL_DEPTH_TEST);
    if (info->depthWrite)
        glDepthMask(GL_TRUE);
    else
        glDepthMask(GL_TRUE);
}