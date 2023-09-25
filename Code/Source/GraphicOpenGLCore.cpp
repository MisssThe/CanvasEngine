//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Core/GraphicOpenGLCore.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "GlobalSetting.h"
#include "../Include/General/Debug.h"

REFLECT_REGISTER(GraphicOpenGLCore) /* NOLINT */
GLFWwindow* window = nullptr;

GraphicOpenGLCore::GraphicOpenGLCore() {
    //初始化window、context
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    window = glfwCreateWindow(GlobalSetting::windowWidth, GlobalSetting::windowHeight, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        Debug::Error("Failed to create GLFW window", "OpenGL Core");
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        Debug::Error("Failed to initialize GLAD", "OpenGL Core");
        return;
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
