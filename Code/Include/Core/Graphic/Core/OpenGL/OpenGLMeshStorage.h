//
// Created by Administrator on 2023/10/13.
//

#ifndef CODE_OPENGLMESHSTORAGE_H
#define CODE_OPENGLMESHSTORAGE_H

#include "../../Assets/MeshAsset.h"

class OpenGLMeshStorage {
public:
    void Bind(var<MeshAsset> mesh);
private:
    unsigned int CompileMesh(var<MeshAsset> mesh);
private:
    std::unordered_map<var<MeshAsset>, unsigned int> meshes;
};


#endif //CODE_OPENGLMESHSTORAGE_H
