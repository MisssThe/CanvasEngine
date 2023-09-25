//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_SHADERASSET_H
#define CODE_SHADERASSET_H


#include "CustomPtr.h"
//#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"

class ShaderAsset : public CustomPtr {
//class ShaderAsset : public CustomAsset {
//class ShaderAsset : public CustomEntity {
public:
    std::string Type() override;

    ~ShaderAsset() override = default;
};


#endif //CODE_SHADERASSET_H
