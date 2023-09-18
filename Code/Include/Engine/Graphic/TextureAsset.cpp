//
// Created by Insomnia on 2023/9/14.
//

#include "TextureAsset.h"

REFLECT_REGISTER(TextureAsset) /* NOLINT */

void TextureAsset::SerializeInInternal(cereal::BinaryInputArchive &archive) {
    archive(a, b, c, d, e);
}

void TextureAsset::SerializeOutInternal(cereal::BinaryOutputArchive &archive) {
    archive(a, b, c, d, e);
}
