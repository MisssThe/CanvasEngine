//
// Created by MisThe on 2023/9/25.
//

#ifndef CODE_GRAPHICFEATURE_H
#define CODE_GRAPHICFEATURE_H


#include "CustomPtr.h"
#include "../RenderData.h"

class GraphicFeature : public CustomPtr {
public:
    ~GraphicFeature() override = default;
    virtual void Invoke(var<RenderData> data) = 0;
};


#endif //CODE_GRAPHICFEATURE_H
