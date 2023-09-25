//
// Created by MisThe on 2023/9/25.
//

#ifndef CODE_SKYBOXFEATURE_H
#define CODE_SKYBOXFEATURE_H


#include "CustomPtr.h"
//#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"

class SkyboxFeature : public CustomPtr {
//class SkyboxFeature : public CustomAsset {
//class SkyboxFeature : public CustomEntity {
public:
    std::string Type() override;

    ~SkyboxFeature() override = default;
};


#endif //CODE_SKYBOXFEATURE_H
