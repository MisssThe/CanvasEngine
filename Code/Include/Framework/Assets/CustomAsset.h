//
// Created by Administrator on 2023/9/13.
//

#ifndef CODE_CUSTOMASSET_H
#define CODE_CUSTOMASSET_H

#include "cereal/types/string.hpp"
#include "cereal/types/memory.hpp"

#include "cereal/archives/binary.hpp"
#include "../CustomPtr.h"

class CustomAsset : public CustomPtr {
public:
    std::string Type() override;
public:
    std::string name;
    std::string path;
public:
    void SerializeIn(cereal::BinaryInputArchive& archive);
    void SerializeOut(cereal::BinaryOutputArchive& archive);
protected:
    virtual void SerializeInInternal(cereal::BinaryInputArchive& archive) = 0;
    virtual void SerializeOutInternal(cereal::BinaryOutputArchive& archive) = 0;
    var<CustomAsset> SerializeInPtr(cereal::BinaryInputArchive& archive);
    void SerializeOutPtr(cereal::BinaryOutputArchive& archive, var<CustomAsset> asset);
};


#endif //CODE_CUSTOMASSET_H
