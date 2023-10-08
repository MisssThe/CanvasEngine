//
// Created by Administrator on 2023/10/7.
//

#ifndef CODE_MESHLOADER_H
#define CODE_MESHLOADER_H


#include "CustomPtr.h"
//#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"

class MeshLoader : public CustomPtr {
//class MeshLoader : public CustomAsset {
//class MeshLoader : public CustomEntity {
public:
    std::string Type() override;

    ~MeshLoader() override = default;
};


#endif //CODE_MESHLOADER_H
