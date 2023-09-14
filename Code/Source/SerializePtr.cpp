//
// Created by Administrator on 2023/9/14.
//

#include "SerializePtr.h"

void SerializePtr::SerializeIn(cereal::BinaryInputArchive &archive) {
    this->SerializeInInternal(archive);
}

void SerializePtr::SerializeOut(cereal::BinaryOutputArchive &archive) {
    this->SerializeOutInternal(archive);
}