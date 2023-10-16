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
    void SetInfo(var<MaterialAsset> info);
    void Release();
private:
    unsigned int CompileShader(var<ShaderAsset> shader);
private:
    std::unordered_map<var<ShaderAsset>, unsigned int> shaders;
};


#endif //CODE_OPENGLSHADERSTORAGE_H
