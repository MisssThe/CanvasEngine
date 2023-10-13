//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_OPENGLGRAPHICCORE_H
#define CODE_OPENGLGRAPHICCORE_H


#include "../GraphicCore.h"
#include "OpenGLMeshStorage.h"
#include "OpenGLShaderStorage.h"

class OpenGLGraphicCore : public GraphicCore {
public:
    OpenGLGraphicCore();
    ~OpenGLGraphicCore() override;
    std::string Type() override;
public:
    bool IsExist() override;
    void BeginFrame() override;
    void EndFrame() override;
    void DrawRenderers(std::queue<std::shared_ptr<Renderer>>& renderers) override;
    void DrawRenderer(std::shared_ptr<Renderer> &renderer) override;
private:
    var<OpenGLMeshStorage> meshStorage;
    var<OpenGLShaderStorage> shaderStorage;
};


#endif //CODE_OPENGLGRAPHICCORE_H
