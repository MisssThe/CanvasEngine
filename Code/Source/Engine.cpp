//
// Created by Insomnia on 2023/9/14.
//

#include "../Include/Engine.h"
#include "../Include/General/Debug.h"
#include "Assets/AssetManager.h"
#include "Scenes/SceneManager.h"
#include "../Include/Engine/Graphic/TextureAsset.h"
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
    for (int i = 0; i < 7000; ++i) {
        auto go = s->AddGameObject(&"go"[i] );
//        safe_cast<Transform>(s->AddComponent(go, "Transform"))->x = i *12;
//        s->AddComponent(go, "Renderer");
//        s->AddComponent(go, "Renderer");
//        s->AddComponent(go, "Renderer");
//        s->AddComponent(go, "Renderer");
    }
    AssetManager::Create("aaa.test",s);
}

void load()
{
    auto scene = SceneManager::Load("aaa.test", true);
}

void Engine::Invoke() {
//    while (true)
//    {
//create();
load();
    std::cout << "--------------------------------------------------------------"<<std::endl;
    SceneManager::Invoke();
//    std::cout << a->Type();
//    std::cout << a->Type();
//    SceneManager::Load("test.scene");
//    }
}
