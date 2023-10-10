//
// Created by Administrator on 2023/10/10.
//

#include "../Include/Core/Graphic/RenderData/CameraManager.h"
#include "../Include/General/Queue.h"

std::queue<var<Camera>> CameraManager::cameras;

void CameraManager::Invoke(std::shared_ptr<CameraInfo> cameraInfo) {
    //对相机进行排序
    //计算相机更新位置后的矩阵信息
}

void CameraManager::RegisterCamera(std::shared_ptr<Camera> camera) {
    if (camera == nullptr)
        return;
    cameras.push(camera);
}

void CameraManager::RemoveCamera(std::shared_ptr<Camera> camera) {
    if (camera == nullptr)
        return;
    Queue::IteratorRemoveBool<var<Camera>>(cameras,[&camera](var<Camera>& c) {
        if (c == camera)
            return false;
        return true;
    });
}

void CameraManager::Release() {
    Queue::Clear(cameras);
}
