//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Core/OpenGL/OpenGLGraphicCore.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GlobalSetting.h"
#include "../Include/General/Debug.h"

REFLECT_REGISTER(OpenGLGraphicCore) /* NOLINT */

GLFWwindow* window = nullptr;
OpenGLGraphicCore::OpenGLGraphicCore() {
    this->meshStorage = new_ptr<OpenGLMeshStorage>();
    this->shaderStorage = new_ptr<OpenGLShaderStorage>();

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    window = glfwCreateWindow(GlobalSetting::windowWidth, GlobalSetting::windowHeight, GlobalSetting::windowName.c_str(), nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
}

OpenGLGraphicCore::~OpenGLGraphicCore() {
    glfwTerminate();
}

void OpenGLGraphicCore::BeginFrame() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLGraphicCore::EndFrame() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool OpenGLGraphicCore::IsExist() {
    return !glfwWindowShouldClose(window);
}

void OpenGLGraphicCore::DrawRenderer(std::shared_ptr<Renderer> &renderer) {
    //Bind Info
    int indexCount = renderer->mesh->indexCount;
    int vertexCount = renderer->mesh->vertexCount;
    this->shaderStorage->Bind(renderer->material->shader);
    this->meshStorage->Bind(renderer->mesh);
    for (auto info : renderer->material->properties)
    {
        this->shaderStorage->SetInfo(info.first, info.second);
    }
//    if (indexCount > 0)
//        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
//    else
//        glDrawArrays(GL_TRIANGLES, vertexCount, GL_FLOAT);
}

void OpenGLGraphicCore::DrawRenderers(std::queue<std::shared_ptr<Renderer>>& renderers) {

}
