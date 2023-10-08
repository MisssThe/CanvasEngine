//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Assets/ShaderAsset.h"
#include <cereal/types/unordered_map.hpp>

[[maybe_unused]] REFLECT_REGISTER(ShaderAsset) /* NOLINT */

void ShaderAsset::SerializeInInternal(inputArchive &archive) {
    archive(this->vertCode, this->fragCode, this->properties);
}

void ShaderAsset::SerializeOutInternal(outputArchive &archive) {
    archive(this->vertCode, this->fragCode, this->properties);
}