//
// Created by Insomnia on 2023/9/14.
//

#ifndef CODE_SCENEMANAGER_H
#define CODE_SCENEMANAGER_H

#include <queue>
#include "Scene.h"

class SceneManager {
public:
    static var<Scene> Load(const std::string& path, bool isSingle = true);
    static void UnLoad(const std::shared_ptr<Scene>& scene);
    static void Invoke();
public:
//    static var<Scene> target;
    static std::unordered_map<std::string, var<CustomEntity>> entityMap;   //只用于初始的序列化
private:
    static std::queue<var<Scene>> scenes;
};


#endif //CODE_SCENEMANAGER_H
