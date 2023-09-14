//
// Created by Administrator on 2023/9/13.
//

#include "../Include/Framework/Assets/CustomAsset.h"
#include "../Include/Framework/Assets/AssetManager.h"

void CustomAsset::SerializeIn(cereal::BinaryInputArchive &archive) {
    this->SerializeInInternal(archive);
}

void CustomAsset::SerializeOut(cereal::BinaryOutputArchive &archive) {
    this->SerializeOutInternal(archive);
}

std::string CustomAsset::Type() {
    return "Asset";
}

var<CustomAsset> CustomAsset::SerializeInPtr(cereal::BinaryInputArchive &archive) {
    std::string ptrPath;
    archive(ptrPath);
    if (ptrPath == "Invalid")
        return nullptr;
    return AssetManager::Instance(ptrPath);
}


void CustomAsset::SerializeOutPtr(cereal::BinaryOutputArchive &archive, std::shared_ptr<CustomAsset> asset) {
    std::string ptrPath = "Invalid";
    if (asset != nullptr)
        ptrPath = asset->path;
    archive(ptrPath);
}