//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_GRAPHICOPENGLCORE_H
#define CODE_GRAPHICOPENGLCORE_H


#include "GraphicCore.h"

class GraphicOpenGLCore : public GraphicCore {
public:
    GraphicOpenGLCore();
    ~GraphicOpenGLCore() override;
    std::string Type() override;
public:
    bool IsExist() override;
    void BeginFrame() override;
    void EndFrame() override;
    void DrawRenderers(std::vector<Renderer>& renderers) override;
};


#endif //CODE_GRAPHICOPENGLCORE_H
