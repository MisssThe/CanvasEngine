//
// Created by Administrator on 2023/10/7.
//

#ifndef CODE_MESHLOADER_H
#define CODE_MESHLOADER_H

#include <string>
#include "../Assets/MeshAsset.h"

class MeshLoader  {
public:
    static void Load(const std::string& path);
private:
    static void LoadOBJ(const std::string& path, var<MeshAsset> meshAsset);
};


#endif //CODE_MESHLOADER_H
