//
// Created by Insomnia on 2023/9/14.
//

#include "TextureAsset.h"

REFLECT_REGISTER(TextureAsset) /* NOLINT */

void TextureAsset::SerializeInInternal(inputArchive &archive) {
    archive(a, b, c, d, e);
}

void TextureAsset::SerializeOutInternal(outputArchive &archive) {
    archive(a, b, c, d, e);
}
