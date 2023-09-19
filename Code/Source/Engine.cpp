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

void Engine::Invoke() {
//    while (true)
//    {

//    var<TextureAsset> ta = new_ptr<TextureAsset>();
//    ta->a = 1;
//    ta->b = 11;
//    ta->c = 111;
//    ta->d = "ddddd";
//    ta->e = "eeeee";
var<Scene> s = new_ptr<Scene>();
var go = new_ptr<GameObject>();
go->name = "test";
//go->AddComponent("Transform");
    for (int i = 0; i < 100; ++i) {
        auto go = s->AddGameObject("go"+i );
        safe_cast<Transform>(go->AddComponent("Transform"))->x = i *12;
        go->AddComponent("Renderer");
    }
//    AssetManager::Create("aaa.te",s);
    std::cout << "--------------------------------------------------------------"<<std::endl;
//    var<Scene> a = safe_cast<Scene>(AssetManager::Instance("aaa.te"));
    auto scene = SceneManager::Load("aaa.te", true);
//    SceneManager::Invoke();
//    std::cout << a->Type();
//    SceneManager::Load("test.scene");
//    SceneManager::Invoke();
//    }
}
