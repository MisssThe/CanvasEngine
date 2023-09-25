//
// Created by Insomnia on 2023/9/14.
//

#include "../Include/Engine.h"
#include "../Include/General/Debug.h"
#include "Assets/AssetManager.h"
#include "Scenes/SceneManager.h"
#include "../Include/Engine/Transform.h"
#include "../Include/Core/Graphic/Graphic.h"
#include "GlobalSetting.h"

void *Engine::operator new(size_t size) {
    return std::malloc(size);
}

void Engine::operator delete(void *p) {

}

Engine::Engine() {
    Debug::Info("Init Engine", "Engine");
    var<GlobalSetting> gs = safe_cast<GlobalSetting>( AssetManager::Instance("GlobalSetting.setting"));
    //初始化core 组件
    Graphic::Initial();
    //加载默认（之前）场景
}

Engine::~Engine() {
    //销毁所有数据
    Graphic::Release();
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
        Graphic::Invoke();
    }
}
