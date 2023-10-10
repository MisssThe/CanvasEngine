//
// Created by Administrator on 2023/10/10.
//

#ifndef CODE_LIGHTMANAGER_H
#define CODE_LIGHTMANAGER_H

#include "Components/Light.h"

class LightManager {
public:
    class LightInfo
    {

    };
public:
    static void Invoke(var<LightInfo> lightInfo);
    static void RegisterLight(var<Light> light);
    static void RemoveLight(var<Light> light);
    static void Release();
private:
};


#endif //CODE_LIGHTMANAGER_H
