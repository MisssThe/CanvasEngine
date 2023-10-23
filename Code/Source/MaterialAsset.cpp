//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Assets/MaterialAsset.h"
#include "Assets/AssetManager.h"
#include <cereal/types/unordered_map.hpp>

REFLECT_REGISTER(MaterialAsset) /* NOLINT */

void MaterialAsset::SerializeInInternal(inputArchive &archive) {
    this->shader = safe_cast<ShaderAsset>( SerializeInPtr(archive));
    archive(this->properties, this->depthTest, this->depthWrite, this->cull);
}

void MaterialAsset::SerializeOutInternal(outputArchive &archive) {
    SerializeOutPtr(archive, this->shader);
    archive(this->properties, this->depthTest, this->depthWrite, this->cull);
}

void MaterialAsset::AddTexture(const std::string &name, const std::string &texture) {

}

void MaterialAsset::AddVector(const std::string &name, float x, float y, float z, float w, MaterialAsset::InfoMode mode) {

}

void MaterialAsset::BindShader(std::shared_ptr<ShaderAsset> &shaderAsset) {
    //清空错误数据类型的材质缓存数据
}

void MaterialAsset::MaterialInfo::serialize(inputArchive &archive) {
    archive(this->flag);
    if (this->flag)
        archive(this->info);
    else
        archive(this->texture->path);
}

void MaterialAsset::MaterialInfo::serialize(outputArchive &archive) {
    archive(this->flag);
    if (this->flag)
        archive(this->info);
    else {
        std::string p;
        archive(p);
        this->texture = safe_cast<TextureAsset>(AssetManager::Instance(p));
    }
}
