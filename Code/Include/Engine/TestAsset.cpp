//
// Created by MisThe on 2023/9/24.
//

#include "TestAsset.h"

REFLECT_REGISTER(TestAsset)

void TestAsset::SerializeInInternal(cereal::BinaryInputArchive &archive) {
archive(this->guid);
}

void TestAsset::SerializeOutInternal(cereal::BinaryOutputArchive &archive) {
archive(this->guid);
}
