//
// Created by Insomnia on 2023/9/14.
//

#ifndef CODE_SCENE_H
#define CODE_SCENE_H


#include <queue>
#include "Assets/CustomAsset.h"
#include "Scenes/CustomEntity.h"

class SceneAsset : public CustomAsset {

};

class Scene : public CustomAsset {
public:
    std::string Type() override;
    ~Scene() override = default;
    void Initial();
    void Enable();
    void Invoke();
    void Disable();
    void Release();
protected:
    void SerializeInInternal(cereal::BinaryInputArchive &archive) override;
    void SerializeOutInternal(cereal::BinaryOutputArchive &archive) override;
private:
    std::queue<var<CustomEntity>> entitiesInitial;
    std::queue<var<CustomEntity>> entitiesEnable;
    std::queue<var<CustomEntity>> entitiesInvoke;
    std::queue<var<CustomEntity>> entitiesDisable;
    std::queue<var<CustomEntity>> entitiesIdle;
    std::queue<var<CustomEntity>> entitiesRelease;
};


#endif //CODE_SCENE_H
