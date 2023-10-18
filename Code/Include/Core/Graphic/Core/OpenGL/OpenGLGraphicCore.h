//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_OPENGLGRAPHICCORE_H
#define CODE_OPENGLGRAPHICCORE_H


#include "../GraphicCore.h"
#include "OpenGLMeshStorage.h"
#include "OpenGLShaderStorage.h"
#include "OpenGLRenderTextureStorage.h"

class OpenGLGraphicCore : public GraphicCore {
public:
    OpenGLGraphicCore();
    ~OpenGLGraphicCore() override;
    std::string Type() override;
public:
    bool IsExist() override;
    void BeginFrame() override;
    void EndFrame() override;
    void SetTarget(var<RenderTexture> renderTexture) override;
    void ClearTarget(Color color, bool clearColor, bool clearDepth) override;
    void DrawRenderers(std::queue<std::shared_ptr<Renderer>>& renderers) override;
    void DrawRenderer(std::shared_ptr<Renderer> &renderer) override;
    var<RenderTexture> GetTemporary(unsigned int width, unsigned int height, unsigned int depth, ColorFormat format) override;
    var<RenderTexture> GetTemporary(unsigned int width, unsigned int height) override;
    var<RenderTexture> GetTemporary(unsigned int width, unsigned int height, unsigned int depth) override;
    void PutTemporary(var<RenderTexture> renderTexture) override;

private:
    var<OpenGLMeshStorage> meshStorage;
    var<OpenGLShaderStorage> shaderStorage;
    var<OpenGLRenderTextureStorage> renderTextureStorage;
};


#endif //CODE_OPENGLGRAPHICCORE_H
