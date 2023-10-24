//
// Created by Administrator on 2023/10/17.
//

#ifndef CODE_OPENGLTEXTURESTORAGE_H
#define CODE_OPENGLTEXTURESTORAGE_H

#include "../../Assets/TextureAsset.h"

class OpenGLTextureStorage  {
public:
    void Bind(var<TextureAsset>& textureAsset, int index);
private:
    unsigned int CompileTexture(var<TextureAsset>& textureAsset);
private:
    std::unordered_map<var<TextureAsset>, unsigned int> textureMap;
};


#endif //CODE_OPENGLTEXTURESTORAGE_H
