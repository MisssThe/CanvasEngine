//
// Created by Administrator on 2023/10/7.
//

#include "../Include/Core/Graphic/AssetsLoader/ShaderLoader.h"
#include "Assets/AssetManager.h"
#include "../Include/General/Tool/IO.h"
#include "../Include/General/Tool/String.h"
#include "../Include/General/Container/Map.h"

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

void ShaderLoader::LoadGLSL(const std::string &path, var<ShaderAsset>& shaderAsset) {
    std::string extension = IO::ExtendName(path);
    if (extension == "vert") {
        IO::ReadFileAsString(path, shaderAsset->vertCode);
    } else if (extension == "frag") {
        IO::ReadFileAsString(path, shaderAsset->fragCode);
    } else if (extension == "prop") {
        //扫描info properties
        shaderAsset->properties.clear();
        std::vector<std::string> vec(3);
        int textureIndex = 0;
        IO::ReadFilePerLine(path, [&vec, &shaderAsset, &textureIndex](std::string &info) {
            if (info.find("uniform") == std::string::npos) {
                return;
            }
            String::Split(info, ' ', vec);
            if (vec[1] == "sampler2D") {
                Map::Insert(shaderAsset->properties, vec[2], ShaderAsset::InfoMode::Texture2D);
            } else if (vec[1] == "vec4") {
                Map::Insert(shaderAsset->properties, vec[2], ShaderAsset::InfoMode::Vec4);
            } else if (vec[1] == "vec3") {

            } else if (vec[1] == "vec2") {

            } else if (vec[1] == "vec1") {

            }
        });
    }
}
