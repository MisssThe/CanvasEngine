//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_GRAPHICCORE_H
#define CODE_GRAPHICCORE_H

#include <queue>
#include "CustomPtr.h"
#include "../RenderData/Components/Renderer.h"
#include "../../../General/Math/Color.h"
#include "RenderTexture.h"

class GraphicCore : public CustomPtr {
public:
    ~GraphicCore() override = default;
public:
//    virtual void DrawRenderer();
    virtual bool IsExist() = 0;
    virtual void BeginFrame() = 0;
    virtual void ExecuteSpace(std::function<void()> space) = 0;
    virtual void EndFrame() = 0;
    virtual void SetTarget(var<RenderTexture> renderTexture) = 0;                           //target为null时绑定会初始target
    virtual void ClearTarget(Color color, bool clearColor, bool clearDepth) = 0;
    virtual var<RenderTexture> GetTemporary(RenderTextureDescribe describe) = 0;
    virtual void PutTemporary(var<RenderTexture> renderTexture) = 0;
    virtual void DrawRenderers(std::queue<std::shared_ptr<Renderer>>& renderers) = 0;
    virtual void DrawRenderer(var<Renderer>& renderer) = 0;
    virtual void Blit(var<Renderer> source, var<Renderer> target, var<MaterialAsset> material) = 0;
    bool IsAsset() final;
};


#endif //CODE_GRAPHICCORE_H
