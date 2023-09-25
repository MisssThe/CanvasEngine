//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_MATERIALASSET_H
#define CODE_MATERIALASSET_H

#include "Assets/CustomAsset.h"

class MaterialAsset : public CustomAsset {
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
public:
    std::string Type() override;
    ~MaterialAsset() override = default;
};


#endif //CODE_MATERIALASSET_H
