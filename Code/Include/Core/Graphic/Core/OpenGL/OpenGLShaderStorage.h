//
// Created by Administrator on 2023/10/13.
//

#ifndef CODE_OPENGLSHADERSTORAGE_H
#define CODE_OPENGLSHADERSTORAGE_H

#include "../../Assets/ShaderAsset.h"
#include "../../Assets/MaterialAsset.h"

class OpenGLShaderStorage {
public:
    void Bind(var<ShaderAsset> shader);
    void SetInfo(const std::string& type, MaterialAsset::MaterialInfo& info);
};


#endif //CODE_OPENGLSHADERSTORAGE_H
