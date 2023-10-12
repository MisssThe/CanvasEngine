//
// Created by Administrator on 2023/10/7.
//

#include "../Include/Core/Graphic/AssetsLoader/ShaderLoader.h"
#include "Assets/AssetManager.h"
#include "../Include/General/IO.h"

bool ShaderRegister = AssetManager::RegisterRefresh([](std::string& path){
    if (path.find("Assets\\Shader") == std::string::npos)
        return;
    ShaderLoader::Load(path);
});

void ShaderLoader::Load(const std::string& path) {
    std::string name = IO::FileName(path);
    std::string newPath = "Caches/Shader/" + name + ".shader";
    var<ShaderAsset> shaderAsset;
    if (IO::Exist(newPath))
        shaderAsset = safe_cast<ShaderAsset>(AssetManager::Instance(newPath));
    else {
        shaderAsset = new_ptr<ShaderAsset>();
        AssetManager::Create(newPath, shaderAsset);
    }

    if (path.find("GLSL") != std::string::npos)
        LoadGLSL(path, shaderAsset);
}

void ShaderLoader::LoadGLSL(const std::string &path, var<ShaderAsset> shaderAsset) {
    std::string extension = IO::ExtendName(path);
    if (extension == "vert") {
        IO::ReadFileAsString(path, shaderAsset->vertCode);
    } else if (extension == "frag") {
        IO::ReadFileAsString(path, shaderAsset->fragCode);
    }
}
