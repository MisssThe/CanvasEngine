//
// Created by Insomnia on 2023/9/14.
//

#include "../Include/Engine.h"
#include "../Include/General/Debug.h"
#include "Assets/AssetManager.h"
#include "Scenes/SceneManager.h"

void *Engine::operator new(size_t size) {
    return std::malloc(size);
}

void Engine::operator delete(void *p) {

}

Engine::Engine() {
    Debug::LogInfo("Init Engine", "Engine");
}

Engine::~Engine() {
    AssetManager::Release();
    Debug::LogInfo("Release Engine", "Engine");
}

void Engine::Invoke() {
//    while (true)
//    {
//    AssetManager::Create("test.scene", new_ptr<Scene>());
    SceneManager::Load("test.scene");
//    SceneManager::Load("");
//    SceneManager::Invoke();
//    }
}
