//
// Created by MisThe on 2023/9/24.
//

#include "TestAsset.h"

REFLECT_REGISTER(TestAsset)

void TestAsset::SerializeInInternal(inputArchive &archive) {
archive(this->guid);
}

void TestAsset::SerializeOutInternal(outputArchive &archive) {
archive(this->guid);
}
