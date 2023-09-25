//
// Created by Insomnia on 2023/9/14.
//

#ifndef CODE_TEXTUREASSET_H
#define CODE_TEXTUREASSET_H



#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"
//#include "CustomPtr.h"

//class TextureAsset : public CustomAsset {
//class TextureAsset : public CustomEntity {
class TextureAsset : public CustomAsset {
public:
    float a,b,c;
    std::string d,e;
public:
    std::string Type() override;
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
public:
    ~TextureAsset() override = default;
};


#endif //CODE_TEXTUREASSET_H
