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
    const Cipher::GUID guid;
    EnableState isEnable;
    AliveState isAlive;
public:
    CustomEntity();
//    std::string Type() override;
    ~CustomEntity() override = default;
    bool IsAsset() final ;
    virtual bool IsGameObject() = 0;
    static void SerializeFinish();
protected:
    var<CustomPtr> SerializeInPtr(cereal::BinaryInputArchive& archive);
    void SerializeOutPtr(cereal::BinaryOutputArchive& archive, var<CustomPtr>& ptr);
public:
    static GuidMap<var<CustomEntity>> entityMap;   //只用于初始的序列化
};


#endif //CODE_CUSTOMENTITY_H
