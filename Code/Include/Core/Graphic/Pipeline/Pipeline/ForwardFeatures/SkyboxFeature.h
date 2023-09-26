//
// Created by MisThe on 2023/9/25.
//

#ifndef CODE_SKYBOXFEATURE_H
#define CODE_SKYBOXFEATURE_H

#include "../../GraphicFeature.h"

class SkyboxFeature : public GraphicFeature {
public:
    void Invoke(std::shared_ptr<RenderData> data) override;
    std::string Type() override;
    ~SkyboxFeature() override = default;
};


#endif //CODE_SKYBOXFEATURE_H
