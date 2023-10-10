//
// Created by Administrator on 2023/10/7.
//

#include "../Include/Core/Graphic/AssetsLoader/ShaderLoader.h"
#include "Assets/AssetManager.h"
#include "../Include/General/IO.h"
#include "../Include/Core/Graphic/Assets/ShaderAsset.h"

bool ShaderRegister = AssetManager::RegisterRefresh([](std::string& path){
    if (path.find("Shader") == path.npos)
        return;
    ShaderLoader::Load(path);
});

void ShaderLoader::Load(const std::string& path) {
    if (path.find("GLSL") != path.npos)
        LoadGLSL(path);
}

void ShaderLoader::LoadGLSL(const std::string &path) {
    std::string extension = IO::ExtendName(path);
    std::string name = IO::FileName(path);
    std::string newPath = "Caches/Shader/" + name + ".shader";
    var<ShaderAsset> shaderAsset;
    if (IO::Exist(newPath))
        shaderAsset = safe_cast<ShaderAsset>(AssetManager::Instance(newPath));
    else {
        shaderAsset = new_ptr<ShaderAsset>();
        AssetManager::Create(newPath, shaderAsset);
    }
    if (extension == "vert") {
        IO::ReadFileAsString(path, shaderAsset->vertCode);
    } else if (extension == "frag") {
        IO::ReadFileAsString(path, shaderAsset->fragCode);
    }
}
