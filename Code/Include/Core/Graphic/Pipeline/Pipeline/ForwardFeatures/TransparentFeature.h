//
// Created by MisThe on 2023/9/25.
//

#ifndef CODE_TRANSPARENTFEATURE_H
#define CODE_TRANSPARENTFEATURE_H


#include "CustomPtr.h"
//#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"

class TransparentFeature : public CustomPtr {
//class TransparentFeature : public CustomAsset {
//class TransparentFeature : public CustomEntity {
public:
    std::string Type() override;

    ~TransparentFeature() override = default;
};


#endif //CODE_TRANSPARENTFEATURE_H
