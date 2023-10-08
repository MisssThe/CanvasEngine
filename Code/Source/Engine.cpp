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
#include "../Include/General/Queue.h"

std::queue<std::function<bool()>> Engine::closes; //NOLINT

void *Engine::operator new(size_t size) {
    return std::malloc(size);
}

void Engine::operator delete(void *p) {

}

Engine::Engine() {
    Debug::Info("Init Engine", "Engine");
    AssetManager::Initial();
    var<GlobalSetting> gs = safe_cast<GlobalSetting>( AssetManager::Instance("Assets/Global/GlobalSetting.setting"));
    gs->windowWidth = 1920;
    gs->windowHeight = 1080;
    gs->windowName = "Canvas";
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
        safe_cast<Transform>(s->AddComponent(go, "Transform"))->x = i * 12;
        s->AddComponent(go, "Renderer");
    }
    Debug::Info("--------------------------------------------------------------");
    AssetManager::Create("Assets/Scene/aaa.scene",s);
    Debug::Info("--------------------------------------------------------------");
}

void load()
{
    Debug::Info("--------------------------------------------------------------");
    auto scene = SceneManager::Load("Assets/Scene/aaa.scene", true);
    Debug::Info("--------------------------------------------------------------");
}

void Engine::Invoke() {
//create();
    load();
//    while (this->IsExist()) {
//        SceneManager::Invoke();
//        Graphic::Invoke();
//    }
}

void Engine::RegisterClose(const std::function<bool()>& call) {
    closes.push(call);
}

bool Engine::IsExist() {
    if (Engine::closes.empty())
        return false;
    bool result = true;
    Queue::Iterator<std::function<bool()>>(Engine::closes, [&result](std::function<bool()>& call) {
        result &= call();
    });
    return result;
}
