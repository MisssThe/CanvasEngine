//
// Created by Insomnia on 2023/9/14.
//

#include "../Include/Engine.h"
#include "../Include/General/Debug.h"
#include "Assets/AssetManager.h"
#include "Scenes/SceneManager.h"
#include "../Include/Engine/Graphic/TextureAsset.h"

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
    for (int i = 0; i < 100; ++i) {
        s->AddGameObject("test"+std::to_string(i));
    }
AssetManager::Create("aaa.te",s);
    std::cout << "--------------------------------------------------------------"<<std::endl;
//    auto a = AssetManager::Instance("aaa.te");
//    std::cout << a->Type();
//    SceneManager::Load("test.scene");
//    SceneManager::Invoke();
//    }
}
