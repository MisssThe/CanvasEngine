//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Core/OpenGL/OpenGLGraphicCore.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GlobalSetting.h"
#include "../Include/General/Tool/Debug.h"
#include "StaticInfo.h"

REFLECT_REGISTER(OpenGLGraphicCore) /* NOLINT */

void screenSizeCall(GLFWwindow* window, int width, int height)
{
//    glViewport(0, 0, width, height);
    StaticInfo::windowWidth = width;
    StaticInfo::windowHeight = height;
}

GLFWwindow* window = nullptr;

OpenGLGraphicCore::OpenGLGraphicCore() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    StaticInfo::windowWidth = GlobalSetting::windowWidth;
    StaticInfo::windowHeight = GlobalSetting::windowHeight;
    window = glfwCreateWindow(GlobalSetting::windowWidth, GlobalSetting::windowHeight, GlobalSetting::windowName.c_str(), nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, screenSizeCall);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);

    glfwSwapInterval( GlobalSetting::isVSync ? 1 : 0);

    this->meshStorage = new_ptr<OpenGLMeshStorage>();
    this->shaderStorage = new_ptr<OpenGLShaderStorage>();
    this->renderTextureStorage = new_ptr<OpenGLRenderTextureStorage>();
}

OpenGLGraphicCore::~OpenGLGraphicCore() {
    this->meshStorage->Release();
    this->shaderStorage->Release();
    glfwTerminate();
}

void OpenGLGraphicCore::BeginFrame() {
    glFinish();
//    glClearColor(0.5f, 0.2f, 0.8f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLGraphicCore::EndFrame() {
    //swap buffer只能交换buffer index 0
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
    this->shaderStorage->SetInfo(renderer->material);
    if (indexCount > 0)
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
    else
        glDrawArrays(GL_TRIANGLES, vertexCount, GL_FLOAT);
}

void OpenGLGraphicCore::DrawRenderers(std::queue<std::shared_ptr<Renderer>>& renderers) {

}

void OpenGLGraphicCore::SetTarget(var<RenderTexture> renderTexture) {
    this->renderTextureStorage->Bind(renderTexture);
}

void OpenGLGraphicCore::ClearTarget(Color color, bool clearColor, bool clearDepth) {
    if (clearColor) {
        glClearColor(color.r(), color.g(), color.b(), color.a());
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    if (clearDepth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLGraphicCore::PutTemporary(var<RenderTexture> renderTexture) {
    this->renderTextureStorage->PutTemporary(renderTexture);
}

std::shared_ptr<RenderTexture> OpenGLGraphicCore::GetTemporary(RenderTextureDescribe describe) {
    return this->renderTextureStorage->GetTemporary(describe);
}

void OpenGLGraphicCore::ExecuteSpace(std::function<void()> space) {
    space();
    glFlush();
}

void OpenGLGraphicCore::Blit(var<Renderer> source, var<Renderer> target, var<MaterialAsset> material) {

}
