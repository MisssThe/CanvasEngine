//
// Created by Administrator on 2023/9/14.
//

#ifndef CODE_GAMEOBJECT_H
#define CODE_GAMEOBJECT_H


#include "CustomEntity.h"

class GameObject : public CustomEntity {
public:
    void Initial() override;
    void Enable() override;
    void Invoke() override;
    void Disable() override;
    void Release() override;
protected:
    void SerializeInInternal(cereal::BinaryInputArchive &archive) override;
    void SerializeOutInternal(cereal::BinaryOutputArchive &archive) override;
public:
    std::string Type() override;
    ~GameObject() override = default;
};


#endif //CODE_GAMEOBJECT_H
