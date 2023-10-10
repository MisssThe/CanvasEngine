//
// Created by Administrator on 2023/10/10.
//

#ifndef CODE_LIGHT_H
#define CODE_LIGHT_H


#include "Scenes/Component.h"

class Light : public Component, public std::enable_shared_from_this<Light> {
public:
    std::string Type() override;
    ~Light() override = default;
    void Initial() override;
    void Enable() override;
    void Invoke() override;
    void Disable() override;
    void Release() override;
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
};


#endif //CODE_LIGHT_H
