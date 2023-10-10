//
// Created by Administrator on 2023/10/10.
//

#ifndef CODE_CAMERA_H
#define CODE_CAMERA_H


#include "Scenes/Component.h"


class Camera : public Component, public std::enable_shared_from_this<Camera> {
public:
    std::string Type() override;
    ~Camera() override = default;
    void Initial() override;
    void Enable() override;
    void Invoke() override;
    void Disable() override;
    void Release() override;
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
};


#endif //CODE_CAMERA_H
