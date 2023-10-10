//
// Created by Administrator on 2023/10/10.
//

#ifndef CODE_CAMERAMANAGER_H
#define CODE_CAMERAMANAGER_H


#include <queue>
#include "Components/Camera.h"

class CameraManager {
public:
    class CameraInfo
    {

    };
public:
    static void Invoke(var<CameraInfo> cameraInfo);
    static void RegisterCamera(var<Camera> camera);
    static void RemoveCamera(var<Camera> camera);
    static void Release();
public:
    static std::queue<var<Camera>> cameras;
};


#endif //CODE_CAMERAMANAGER_H
