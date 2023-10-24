//
// Created by Administrator on 2023/9/14.
//

#ifndef CODE_GAMEOBJECT_H
#define CODE_GAMEOBJECT_H


#include <queue>
#include "CustomEntity.h"
#include "Component.h"


class GameObject : public CustomEntity {
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
public:
    void SetActive(bool flag) final;
    void Destroy() final;
    bool IsGameObject() final;
    std::string Type() override;
    ~GameObject() override = default;
public:
    std::string name;
    std::queue<var<Component>> components;
};


#endif //CODE_GAMEOBJECT_H
