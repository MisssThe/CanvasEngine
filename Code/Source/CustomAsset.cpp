//
// Created by Administrator on 2023/9/13.
//

#include "../Include/Framework/Assets/CustomAsset.h"
#include "../Include/Framework/Assets/AssetManager.h"

std::string CustomAsset::Type() {
    return "Asset";
}

var<CustomAsset> CustomAsset::SerializeInPtr(inputArchive &archive) {
    std::string ptrPath;
    archive(ptrPath);
    if (ptrPath == "Invalid")
        return nullptr;
    return AssetManager::Instance(ptrPath);
}


void CustomAsset::SerializeOutPtr(outputArchive &archive, std::shared_ptr<CustomAsset> asset) {
    std::string ptrPath = "Invalid";
    if (asset != nullptr)
        ptrPath = asset->path;
    archive(ptrPath);
}

bool CustomAsset::IsAsset() {
    return true;
}

CustomAsset::~CustomAsset() {

}
