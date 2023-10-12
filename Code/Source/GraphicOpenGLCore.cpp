//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Core/OpenGL/GraphicOpenGLCore.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GlobalSetting.h"
#include "../Include/General/Debug.h"

REFLECT_REGISTER(GraphicOpenGLCore) /* NOLINT */

GLFWwindow* window = nullptr;
GraphicOpenGLCore::GraphicOpenGLCore() {
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

GraphicOpenGLCore::~GraphicOpenGLCore() {
    glfwTerminate();
}

void GraphicOpenGLCore::DrawRenderers(std::vector<Renderer>& renderers) {
    //绘制传入的renderers
    for (auto renderer : renderers) {
        //绑定对应资源
        //调用绘制接口
        Debug::Info("draw renderer");
//        glDrawElements()
    }
}

void GraphicOpenGLCore::BeginFrame() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void GraphicOpenGLCore::EndFrame() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool GraphicOpenGLCore::IsExist() {
    return !glfwWindowShouldClose(window);
}
