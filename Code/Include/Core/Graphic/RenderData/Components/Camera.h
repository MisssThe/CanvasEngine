//
// Created by Administrator on 2023/10/10.
// 相机矩阵信息默认每帧刷新一次，可以通过UpdateInfo强制刷新
//

#ifndef CODE_CAMERA_H
#define CODE_CAMERA_H


#include "Scenes/Component.h"
#include "../../../../General/Math/CommonMath.h"

class Camera : public Component, public std::enable_shared_from_this<Camera> {
public:
    std::string Type() override;
    ~Camera() override = default;
    void Initial() override;
    void Enable() override;
    void Invoke() override;
    void Disable() override;
    void Release() override;
    void UpdateInfo();
public:
    enum ProjectionMode
    {
        Perspective, Orthographic
    };
    ProjectionMode projectionMode;
    CommonMath::Float2 clipPlane;
    CommonMath::Float4 viewPort;

protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
};


#endif //CODE_CAMERA_H
