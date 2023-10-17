//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_GRAPHICCORE_H
#define CODE_GRAPHICCORE_H

#include <queue>
#include "CustomPtr.h"
#include "../RenderData/Components/Renderer.h"
#include "../Assets/RenderTextureAsset.h"
#include "../../../General/Math/Color.h"

class GraphicCore : public CustomPtr {
public:
    ~GraphicCore() override = default;
public:
//    virtual void DrawRenderer();
    virtual bool IsExist() = 0;
    virtual void BeginFrame() = 0;
    virtual void SetTarget(var<RenderTextureAsset> renderTexture) = 0;
    virtual void ClearTarget(Color color, bool clearColor, bool clearDepth) = 0;
    virtual void DrawRenderers(std::queue<std::shared_ptr<Renderer>>& renderers) = 0;
    virtual void DrawRenderer(var<Renderer>& renderer) = 0;
    virtual void EndFrame() = 0;
    bool IsAsset() final;
};


#endif //CODE_GRAPHICCORE_H
