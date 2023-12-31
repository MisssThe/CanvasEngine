//
// Created by Insomnia on 2023/9/14.
//

#include "../Include/Engine.h"
#include "../Include/General/Tool/Debug.h"
#include "Assets/AssetManager.h"
#include "Scenes/SceneManager.h"
#include "../Include/Core/Graphic/Graphic.h"
#include "GlobalSetting.h"
#include "../Include/General/Container/Queue.h"
#include "../Include/Engine/Transform.h"

std::queue<std::function<bool()>> Engine::closes; //NOLINT

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
    var<MaterialAsset> lit = new_ptr<MaterialAsset>();
    var shader = safe_cast<ShaderAsset>(AssetManager::Instance("Caches/Shader/unlit.shader"));
    lit->BindShader(shader);
    lit->AddTexture("albedoTex", "Caches/Texture/test.texture");
    lit->AddTexture("normalTex", "Caches/Texture/normal.texture");
    AssetManager::Create("Caches/Material/lit.mat", lit);
    var<Scene> s = SceneManager::Create();
    for (int i = 0; i < 30; ++i) {
        auto go = s->AddGameObject("go");
        var<Renderer> renderer = safe_cast<Renderer>(s->AddComponent(go, "Renderer"));
        s->AddComponent(go, "Transform");
        renderer->material = safe_cast<MaterialAsset>( AssetManager::Instance("Caches/Material/lit.mat"));
        renderer->mesh = safe_cast<MeshAsset>( AssetManager::Instance("Caches/Mesh/quad.mesh"));
    }
    //添加一个相机
    auto camera = s->AddGameObject("camera");
    var<Camera> c = safe_cast<Camera>(s->AddComponent(camera, "Camera"));


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
create();
//    load();
    while (this->IsExist()) {
        SceneManager::Invoke();
        Graphic::Invoke();
    }
}

void Engine::RegisterClose(const std::function<bool()>& call) {
    closes.push(call);
}

bool Engine::IsExist() const {
    if (this->isExist)
        return false;
    if (Engine::closes.empty())
        return false;
    bool result = true;
    Queue::Iterator<std::function<bool()>>(Engine::closes, [&result](std::function<bool()>& call) {
        result &= call();
    });
    return result;
}
