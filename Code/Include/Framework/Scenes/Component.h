//
// Created by Administrator on 2023/9/15.
//

#ifndef CODE_COMPONENT_H
#define CODE_COMPONENT_H

#include "CustomEntity.h"

class Component : public CustomEntity {
public:
    ~Component() override = default;
public:
    virtual void Initial() = 0;
    virtual void Enable() = 0;
    virtual void Invoke() = 0;
    virtual void Disable() = 0;
    virtual void Release() = 0;
    bool IsGameObject() final ;
};


#endif //CODE_COMPONENT_H
