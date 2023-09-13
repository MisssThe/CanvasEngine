//
// Created by Administrator on 2023/9/13.
//

#include "../Include/Framework/Assets/CustomAsset.h"

void CustomAsset::SerializeIn(cereal::BinaryInputArchive &archive) {
    this->SerializeInInternal(archive);
}

void CustomAsset::SerializeOut(cereal::BinaryOutputArchive &archive) {
    this->SerializeOutInternal(archive);
}

std::string CustomAsset::Type() {
    return "Asset";
}
