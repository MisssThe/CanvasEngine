//
// Created by Administrator on 2023/9/14.
//

#ifndef CODE_CUSTOMENTITY_H
#define CODE_CUSTOMENTITY_H


#include "CustomPtr.h"
#include "SerializePtr.h"
#include "../../General/Cipher.h"
#include <map>

enum AliveState
{
    AliveTrue, AliveFalse, AliveNone
};

enum EnableState
{
    EnableTrue, EnableFalse, EnableNone
};

class CustomEntity : public CustomPtr, public SerializePtr {
public:
    EnableState isEnable;
    AliveState isAlive;
public:
    CustomEntity();
//    std::string Type() override;
    ~CustomEntity() override = default;
    bool IsAsset() final ;
    virtual bool IsGameObject() = 0;
    static void SerializeFinish();
    virtual void SetActive(bool flag) = 0;
    virtual void Destroy() = 0;
protected:
    var<CustomPtr> SerializeInPtr(inputArchive& archive);
    void SerializeOutPtr(outputArchive& archive, var<CustomPtr>& ptr);
public:
    static std::unordered_map<long long, var<CustomEntity>> entityMap;   //只用于初始的序列化
};


#endif //CODE_CUSTOMENTITY_H
