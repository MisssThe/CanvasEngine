//
// Created by Administrator on 2023/9/13.
//

#ifndef CODE_CUSTOMASSET_H
#define CODE_CUSTOMASSET_H

#include "../CustomPtr.h"
#include "SerializePtr.h"

class CustomAsset : public CustomPtr, public SerializePtr {
public:
    std::string Type() override;
    bool IsAsset() final ;
    ~CustomAsset() override;
public:
    std::string name;
    std::string path;
protected:
    var<CustomAsset> SerializeInPtr(inputArchive& archive);
    void SerializeOutPtr(outputArchive& archive, var<CustomAsset> asset);
};


#endif //CODE_CUSTOMASSET_H
