//
// Created by Administrator on 2023/10/7.
// 将glsl、hlsl、cg等shader转换为内置格式
//

#ifndef CODE_SHADERLOADER_H
#define CODE_SHADERLOADER_H


#include <string>
#include "../Assets/ShaderAsset.h"

class ShaderLoader {
public:
    static void Load(const std::string& path);
private:
    static void LoadGLSL(const std::string& path, var<ShaderAsset>& shaderAsset);
};


#endif //CODE_SHADERLOADER_H
