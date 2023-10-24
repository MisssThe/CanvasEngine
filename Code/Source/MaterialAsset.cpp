//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Assets/MaterialAsset.h"
#include "Assets/AssetManager.h"
#include "../Include/General/Container/Map.h"
#include <cereal/types/unordered_map.hpp>
#include <utility>

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
    this->AddTexture(name, safe_cast<TextureAsset>( AssetManager::Instance(texture)));
}

void MaterialAsset::AddTexture(const std::string &name, std::shared_ptr<TextureAsset> texture) {
    MaterialInfo info;
    info.flag = ShaderAsset::InfoMode::Texture2D;
    info.texture = std::move(texture);
    Map::Insert<std::string, MaterialInfo>(this->properties, name, info);
}

void MaterialAsset::BindShader(std::shared_ptr<ShaderAsset> &shaderAsset) {
    //清空错误数据类型的材质缓存数据
    this->shader = shaderAsset;
}

void MaterialAsset::AddVector(const std::string &name, float x) {
    MaterialInfo info;
    info.flag = ShaderAsset::InfoMode::Vec1;
    info.info[0] = x;
    Map::Insert<std::string, MaterialInfo>(this->properties, name, info);
}

void MaterialAsset::AddVector(const std::string &name, float x, float y) {
    MaterialInfo info;
    info.flag = ShaderAsset::InfoMode::Vec2;
    info.info[0] = x;
    info.info[1] = y;
    Map::Insert<std::string, MaterialInfo>(this->properties, name, info);
}

void MaterialAsset::AddVector(const std::string &name, float x, float y, float z) {
    MaterialInfo info;
    info.flag = ShaderAsset::InfoMode::Vec3;
    info.info[0] = x;
    info.info[1] = y;
    info.info[2] = z;
    Map::Insert<std::string, MaterialInfo>(this->properties, name, info);
}

void MaterialAsset::AddVector(const std::string &name, float x, float y, float z, float w) {
    MaterialInfo info;
    info.flag = ShaderAsset::InfoMode::Vec4;
    info.info[0] = x;
    info.info[1] = y;
    info.info[2] = z;
    info.info[3] = w;
    Map::Insert<std::string, MaterialInfo>(this->properties, name, info);
}

void MaterialAsset::MaterialInfo::serialize(inputArchive &archive) {
    archive(this->flag);
    if (this->flag != ShaderAsset::Texture2D)
        archive(this->info);
    else {
        std::string p;
        archive(p);
        this->texture = safe_cast<TextureAsset>(AssetManager::Instance(p));
    }
}

void MaterialAsset::MaterialInfo::serialize(outputArchive &archive) {
    archive(this->flag);
    if (this->flag != ShaderAsset::Texture2D)
        archive(this->info);
    else
        archive(this->texture->path);
}
