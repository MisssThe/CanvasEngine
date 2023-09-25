//
// Created by MisThe on 2023/9/25.
//

#ifndef CODE_GRAPHICFEATURE_H
#define CODE_GRAPHICFEATURE_H


#include "CustomPtr.h"

class GraphicFeature : public CustomPtr {
public:
    std::string Type() override;
    ~GraphicFeature() override = default;
};


#endif //CODE_GRAPHICFEATURE_H
