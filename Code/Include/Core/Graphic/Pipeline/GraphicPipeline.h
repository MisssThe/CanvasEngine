//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_GRAPHICPIPELINE_H
#define CODE_GRAPHICPIPELINE_H


#include "CustomPtr.h"
#include "../RenderData.h"

class GraphicPipeline : public CustomPtr {
public:
    ~GraphicPipeline() override = default;
    virtual void Invoke(var<RenderData> data) = 0;
};


#endif //CODE_GRAPHICPIPELINE_H
