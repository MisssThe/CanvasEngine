//
// Created by Administrator on 2023/9/14.
//

#ifndef CODE_SERIALIZEPTR_H
#define CODE_SERIALIZEPTR_H

#include "cereal/types/string.hpp"
#include "cereal/archives/binary.hpp"

class SerializePtr {
public:
    void SerializeIn(cereal::BinaryInputArchive& archive);
    void SerializeOut(cereal::BinaryOutputArchive& archive);
protected:
    virtual void SerializeInInternal(cereal::BinaryInputArchive& archive) = 0;
    virtual void SerializeOutInternal(cereal::BinaryOutputArchive& archive) = 0;
};


#endif //CODE_SERIALIZEPTR_H
