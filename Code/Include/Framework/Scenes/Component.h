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
    //避免存虚函数占用内存
    virtual void Initial();
    virtual void Enable();
    virtual void Invoke();
    virtual void Disable();
    virtual void Release();
    bool IsGameObject() final;
    void SetActive(bool flag) final;
    void Destroy() final;
};


#endif //CODE_COMPONENT_H
