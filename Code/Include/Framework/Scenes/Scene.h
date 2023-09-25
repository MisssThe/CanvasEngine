//
// Created by Insomnia on 2023/9/14.
// 组件在创建后一定会执行一次Initial操作
// 组件在销毁时会先后执行Disable、Release操作
//

#ifndef CODE_SCENE_H
#define CODE_SCENE_H


#include <queue>
#include "Assets/CustomAsset.h"
#include "Component.h"
#include "GameObject.h"

class Scene : public CustomAsset {
public:
    std::string Type() override;
    ~Scene() override = default;
    void Initial();
    void Enable();
    void Invoke();
    void Disable();
    void Release();
    void AddGameObject(var<GameObject>& go);
    var<GameObject> AddGameObject(std::string name);
    void AddComponent(var<GameObject>& go, var<Component>& com);
    void AddComponent(var<GameObject> go, std::string& com);
protected:
    void SerializeInInternal(cereal::BinaryInputArchive &archive) override;
    void SerializeOutInternal(cereal::BinaryOutputArchive &archive) override;
private:
    void SerializeInDeque(cereal::BinaryInputArchive &archive);
    void SerializeOutDeque(cereal::BinaryOutputArchive &archive, std::deque<var<Component>>& que);
private:
    //为了保证数据紧密，将component额外存放在Scene中用以遍历
    //component在使用中以低增删、高遍历的形式运行
    //经过测试deque的二级素组结构在遍历中效率略高于vector（有点反常识）
    std::deque<var<Component>> componentInitial;
    std::deque<var<Component>> componentEnable;
    std::deque<var<Component>> componentInvoke;
    std::deque<var<Component>> componentDisable;
    std::deque<var<Component>> componentIdle;
    std::deque<var<Component>> componentRelease;
    std::deque<var<GameObject>> gameObjects;
};


#endif //CODE_SCENE_H
