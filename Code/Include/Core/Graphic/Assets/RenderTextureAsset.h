//
// Created by Administrator on 2023/10/17.
//

#ifndef CODE_RENDERTEXTUREASSET_H
#define CODE_RENDERTEXTUREASSET_H

#include "Assets/CustomAsset.h"

class RenderTextureAsset : public CustomAsset {
public:
    std::string Type() override;
    ~RenderTextureAsset() override = default;
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
};


#endif //CODE_RENDERTEXTUREASSET_H
