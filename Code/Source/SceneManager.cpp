//
// Created by Insomnia on 2023/9/14.
//

#include "Scenes/SceneManager.h"
#include "Assets/AssetManager.h"
#include "../Include/General/Container/Queue.h"

std::queue<var<Scene>> SceneManager::scenes;
//var<Scene> SceneManager::target = nullptr;

void SceneManager::Invoke() {
    Queue::Iterator<var<Scene>>(scenes, [](var<Scene> &scene) { scene->Initial(); });
    Queue::Iterator<var<Scene>>(scenes, [](var<Scene> &scene) { scene->Enable(); });
    Queue::Iterator<var<Scene>>(scenes, [](var<Scene> &scene) { scene->Invoke(); });
    Queue::Iterator<var<Scene>>(scenes, [](var<Scene> &scene) { scene->Disable(); });
    Queue::Iterator<var<Scene>>(scenes, [](var<Scene> &scene) { scene->Release(); });
}

var<Scene> SceneManager::Load(const std::string& path, bool isSingle) {
    auto asset = AssetManager::Instance(path);
    if (asset == nullptr)
        return nullptr;
    if (isSingle)
        Queue::Iterator<var<Scene>>(scenes, [](var<Scene>& scene) { UnLoad(scenes.front()); });
    auto scene = safe_cast<Scene>(asset);
    scenes.push(scene);
    return scene;
}

void SceneManager::UnLoad(const std::shared_ptr<Scene>& scene) {

}

var<Scene> SceneManager::Create(bool isSingle) {
    if (isSingle)
        Queue::Iterator<var<Scene>>(scenes, [](var<Scene>& scene) { UnLoad(scenes.front()); });
    auto scene = new_ptr<Scene>();
    scenes.push(scene);
    return scene;
}
