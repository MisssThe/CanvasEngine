//
// Created by Insomnia on 2023/9/14.
//

#ifndef CODE_TEXTUREASSET_H
#define CODE_TEXTUREASSET_H



//#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"
#include "CustomPtr.h"

//class TextureAsset : public CustomAsset {
//class TextureAsset : public CustomEntity {
class TextureAsset : public CustomPtr {
public:
    std::string Type() override;

    ~TextureAsset() override = default;
};


#endif //CODE_TEXTUREASSET_H
