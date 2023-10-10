//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_GRAPHICCORE_H
#define CODE_GRAPHICCORE_H

#include "CustomPtr.h"
#include "../RenderData/Components/Renderer.h"

class GraphicCore : public CustomPtr {
public:
    ~GraphicCore() override = default;
public:
//    virtual void DrawRenderer();
    virtual bool IsExist() = 0;
    virtual void BeginFrame() = 0;
    virtual void DrawRenderers(std::vector<Renderer>& renderers) = 0;
    virtual void EndFrame() = 0;
};


#endif //CODE_GRAPHICCORE_H
