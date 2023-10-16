//
// Created by Administrator on 2023/10/13.
//

#ifndef CODE_OPENGLMESHSTORAGE_H
#define CODE_OPENGLMESHSTORAGE_H

#include <queue>
#include "../../Assets/MeshAsset.h"

class OpenGLMeshStorage {
public:
    void Bind(var<MeshAsset> mesh);
    void Release();
private:
    unsigned int CompileMesh(var<MeshAsset> mesh);
private:
    std::unordered_map<var<MeshAsset>, unsigned int> meshes;
    std::queue<unsigned int> buffers;
};


#endif //CODE_OPENGLMESHSTORAGE_H
