//
// Created by Administrator on 2023/10/17.
//

#ifndef CODE_RENDERTEXTURE_H
#define CODE_RENDERTEXTURE_H


#include "CustomPtr.h"
//#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"

class RenderTexture : public CustomPtr {
public:
    std::string Type() override;
    ~RenderTexture() override = default;
};


#endif //CODE_RENDERTEXTURE_H
