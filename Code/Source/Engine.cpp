//
// Created by Insomnia on 2023/9/14.
//

#include "../Include/Engine.h"
#include "../Include/General/Debug.h"
#include "Assets/AssetManager.h"
#include "Scenes/SceneManager.h"
#include "../Include/Engine/Transform.h"

void *Engine::operator new(size_t size) {
    return std::malloc(size);
}

void Engine::operator delete(void *p) {

}

Engine::Engine() {
    Debug::Info("Init Engine", "Engine");
}

Engine::~Engine() {
    AssetManager::Release();
    Debug::Info("Release Engine", "Engine");
}

void create()
{
    var<Scene> s = SceneManager::Create();
    for (int i = 0; i < 70; ++i) {
        auto go = s->AddGameObject("go");
        safe_cast<Transform>(s->AddComponent(go, "Transform"))->x = i *12;
        s->AddComponent(go, "Renderer");
    }
    Debug::Info("--------------------------------------------------------------");
    AssetManager::Create("aaa.test",s);
    Debug::Info("--------------------------------------------------------------");
}

void load()
{
    Debug::Info("--------------------------------------------------------------");
    auto scene = SceneManager::Load("aaa.test", true);
    Debug::Info("--------------------------------------------------------------");
}

void Engine::Invoke() {
//create();
    load();
    while (true) {
        SceneManager::Invoke();
    }
}
