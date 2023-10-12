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

protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
};


#endif //CODE_TEXTUREASSET_H
