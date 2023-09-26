//
// Created by MisThe on 2023/9/25.
//

#ifndef CODE_FORWARDPIPELINE_H
#define CODE_FORWARDPIPELINE_H


#include "CustomPtr.h"
#include "../GraphicPipeline.h"
class ForwardPipeline : public GraphicPipeline {
public:
    ForwardPipeline();
    std::string Type() override;
    void Invoke(std::shared_ptr<RenderData> data) override;
    ~ForwardPipeline() override = default;
};


#endif //CODE_FORWARDPIPELINE_H
