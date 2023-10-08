//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_SHADERASSET_H
#define CODE_SHADERASSET_H


#include "Assets/CustomAsset.h"

class ShaderAsset : public CustomAsset {
public:
    std::string Type() override;
    ~ShaderAsset() override = default;
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
public:
    enum ShaderPropertyType
    {
        Float, Float2, Float3, Float4,
        Texture2D, Texture3D,
    };
public:
    std::string vertCode;
    std::string fragCode;
public:
    std::unordered_map<std::string, ShaderPropertyType> properties;
};


#endif //CODE_SHADERASSET_H
