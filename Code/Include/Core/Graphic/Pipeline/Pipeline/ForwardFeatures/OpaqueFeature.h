//
// Created by MisThe on 2023/9/25.
//

#ifndef CODE_OPAQUEFEATURE_H
#define CODE_OPAQUEFEATURE_H

#include "../../GraphicFeature.h"

class OpaqueFeature : public GraphicFeature{
public:
    std::string Type() override;
    ~OpaqueFeature() override = default;
    void Invoke(std::shared_ptr<RenderData> data) override;
};


#endif //CODE_OPAQUEFEATURE_H
