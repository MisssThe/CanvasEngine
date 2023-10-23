//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Assets/TextureAsset.h"

REFLECT_REGISTER(TextureAsset) /* NOLINT */

void TextureAsset::SerializeInInternal(inputArchive &archive) {
    archive(filter, repeat, mipCount, texturePath);
}

void TextureAsset::SerializeOutInternal(outputArchive &archive) {
    archive(filter, repeat, mipCount, texturePath);
}