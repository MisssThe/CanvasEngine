//
// Created by Administrator on 2023/10/23.
//

#include "../Include/Core/Graphic/AssetsLoader/TextureLoader.h"
#include "Assets/AssetManager.h"
#include "../Include/General/Tool/IO.h"

bool TextureRegister = AssetManager::RegisterRefresh([](std::string& path){
    if (path.find("Assets\\Texture") == std::string::npos)
        return;
    TextureLoader::Load(path);
});

void TextureLoader::Load(const std::string &path) {
    std::string name = IO::FileName(path);
    std::string newPath = "Caches/Texture/" + name + ".texture";
    var<TextureAsset> textureAsset;
    if (IO::Exist(newPath))
        textureAsset = safe_cast<TextureAsset>(AssetManager::Instance(newPath));
    else {
        textureAsset = new_ptr<TextureAsset>();
        AssetManager::Create(newPath, textureAsset);
    }
    textureAsset->texturePath = path;
}
