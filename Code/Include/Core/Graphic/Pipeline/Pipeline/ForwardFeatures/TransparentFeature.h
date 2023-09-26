//
// Created by MisThe on 2023/9/25.
//

#ifndef CODE_TRANSPARENTFEATURE_H
#define CODE_TRANSPARENTFEATURE_H


#include "../../GraphicFeature.h"

class TransparentFeature : public GraphicFeature {
public:
    void Invoke(std::shared_ptr<RenderData> data) override;
    std::string Type() override;
    ~TransparentFeature() override = default;
};


#endif //CODE_TRANSPARENTFEATURE_H
