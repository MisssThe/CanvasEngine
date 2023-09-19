//
// Created by MisThe on 2023/9/19.
//

#ifndef CODE_TRANSFORM_H
#define CODE_TRANSFORM_H

#include "Scenes/Component.h"

class Transform : public Component {
public:
    float x,y,z;
public:
    std::string Type() override;
    void Initial() override;
    void Enable() override;
    void Invoke() override;
    void Disable() override;
    void Release() override;
    ~Transform() override = default;
protected:
    void SerializeInInternal(cereal::BinaryInputArchive &archive) override;
    void SerializeOutInternal(cereal::BinaryOutputArchive &archive) override;
};


#endif //CODE_TRANSFORM_H
