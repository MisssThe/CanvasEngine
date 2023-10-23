//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_TEXTUREASSET_H
#define CODE_TEXTUREASSET_H

#include "Assets/CustomAsset.h"

class TextureAsset : public CustomAsset {
public:
    std::string Type() override;
    ~TextureAsset() override = default;
public:
    enum FilterMode
    {
        Point, Linear
    };
    enum RepeatMode
    {
        Repeat, Mirror, Clamp, ClampWithColor
    };
public:
    FilterMode filter;
    RepeatMode repeat;
    int mipCount;
    std::string texturePath;
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
};


#endif //CODE_TEXTUREASSET_H
