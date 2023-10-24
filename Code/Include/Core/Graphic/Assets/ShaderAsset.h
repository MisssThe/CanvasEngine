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
    enum InfoMode
    {
        Vec1, Vec2, Vec3, Vec4, Texture2D
    };
public:
    std::string vertCode;
    std::string fragCode;
public:
    std::unordered_map<std::string, InfoMode> properties;
    std::unordered_map<std::string, int> propertiesID;
};


#endif //CODE_SHADERASSET_H
