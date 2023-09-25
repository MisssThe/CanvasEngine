//
// Created by MisThe on 2023/9/25.
//

#ifndef CODE_OPAQUEFEATURE_H
#define CODE_OPAQUEFEATURE_H


#include "CustomPtr.h"
//#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"

class OpaqueFeature : public CustomPtr {
//class OpaqueFeature : public CustomAsset {
//class OpaqueFeature : public CustomEntity {
public:
    std::string Type() override;

    ~OpaqueFeature() override = default;
};


#endif //CODE_OPAQUEFEATURE_H
