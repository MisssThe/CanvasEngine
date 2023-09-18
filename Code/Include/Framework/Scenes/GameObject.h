//
// Created by Administrator on 2023/9/14.
//

#ifndef CODE_GAMEOBJECT_H
#define CODE_GAMEOBJECT_H


#include <queue>
#include "CustomEntity.h"

class Component;

class GameObject : public CustomEntity {
protected:
    void SerializeInInternal(cereal::BinaryInputArchive &archive) override;
    void SerializeOutInternal(cereal::BinaryOutputArchive &archive) override;
public:
    bool IsGameObject() final ;
    std::string Type() override;
    ~GameObject() override = default;
public:
    std::string name;
    std::queue<var<Component>> components;
};


#endif //CODE_GAMEOBJECT_H
