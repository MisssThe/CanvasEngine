//
// Created by Administrator on 2023/9/14.
//

#ifndef CODE_CUSTOMENTITY_H
#define CODE_CUSTOMENTITY_H


#include "CustomPtr.h"
#include "SerializePtr.h"

class CustomEntity : public CustomPtr, public SerializePtr {
public:
    const std::string id;
public:
    CustomEntity();
//    std::string Type() override;
    ~CustomEntity() override = default;
    bool IsAsset() override;
public:
    virtual void Initial() = 0;
    virtual void Enable() = 0;
    virtual void Invoke() = 0;
    virtual void Disable() = 0;
    virtual void Release() = 0;
public:
    bool isEnable{};
    bool isAlive{};
protected:
    var<CustomPtr> SerializeInPtr(cereal::BinaryInputArchive& archive);
    void SerializeOutPtr(cereal::BinaryOutputArchive& archive, var<CustomPtr>& ptr);
};


#endif //CODE_CUSTOMENTITY_H
