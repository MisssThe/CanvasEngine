//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_TEXTUREASSET_H
#define CODE_TEXTUREASSET_H


#include "CustomPtr.h"
//#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"

class TextureAsset : public CustomPtr {
//class TextureAsset : public CustomAsset {
//class TextureAsset : public CustomEntity {
public:
    std::string Type() override;

    ~TextureAsset() override = default;
};


#endif //CODE_TEXTUREASSET_H
