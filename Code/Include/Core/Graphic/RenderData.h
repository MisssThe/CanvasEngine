//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_RENDERDATA_H
#define CODE_RENDERDATA_H


#include "CustomPtr.h"

class RenderData : public CustomPtr {
public:
    std::string Type() override;
    ~RenderData() override = default;
public:
    void Update();
    void Clear();
};


#endif //CODE_RENDERDATA_H
