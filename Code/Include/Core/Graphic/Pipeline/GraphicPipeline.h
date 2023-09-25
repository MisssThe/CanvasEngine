//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_GRAPHICPIPELINE_H
#define CODE_GRAPHICPIPELINE_H


#include "CustomPtr.h"

class GraphicPipeline : public CustomPtr {
public:
    std::string Type() override;

    ~GraphicPipeline() override = default;
};


#endif //CODE_GRAPHICPIPELINE_H
