//
// Created by Administrator on 2023/9/14.
//

#include "SerializePtr.h"

void SerializePtr::SerializeIn(inputArchive &archive) {
    this->SerializeInInternal(archive);
}

void SerializePtr::SerializeOut(outputArchive &archive) {
    this->SerializeOutInternal(archive);
}