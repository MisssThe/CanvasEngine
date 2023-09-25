//
// Created by Administrator on 2023/9/14.
// 小心unsigned int/float/double，没有做对应支持会造成bad alloc
// string在达到一定数量后会异常(将二进制替换为json后则正常)
// Json与Binary对比(没得比：binary大小三分之一、速度四分之一)
//

#ifndef CODE_SERIALIZEPTR_H
#define CODE_SERIALIZEPTR_H

#include "cereal/types/string.hpp"
#include "cereal/archives/binary.hpp"
//#include <cereal/archives/json.hpp>

//Binary
typedef cereal::BinaryInputArchive inputArchive;
typedef cereal::BinaryOutputArchive outputArchive;

//Json
//typedef cereal::JSONInputArchive inputArchive;
//typedef cereal::JSONOutputArchive outputArchive;

class SerializePtr {
public:
    void SerializeIn(inputArchive& archive);
    void SerializeOut(outputArchive& archive);
protected:
    virtual void SerializeInInternal(inputArchive& archive) = 0;
    virtual void SerializeOutInternal(outputArchive& archive) = 0;
};


#endif //CODE_SERIALIZEPTR_H
