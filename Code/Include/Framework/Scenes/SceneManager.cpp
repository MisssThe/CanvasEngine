//
// Created by Insomnia on 2023/9/14.
//

#include "SceneManager.h"
#include "Assets/AssetManager.h"

void SceneManager::Invoke() {

}

var<Scene> SceneManager::Load(const std::string& path, bool isSingle) {
    auto asset = AssetManager::Instance(path);
    if (asset == nullptr)
        return nullptr;
    if (isSingle)
        for (unsigned int index = 0; index < scenes.size(); ++index) {
            UnLoad(scenes.front());
            scenes.pop();
        }
    auto scene = safe_cast<Scene>(asset);
    scenes.push(scene);
    return scene;
}

void SceneManager::UnLoad(const std::shared_ptr<Scene>& scene) {

}
