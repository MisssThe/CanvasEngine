//
// Created by Administrator on 2023/10/13.
//

#include "../Include/Core/Graphic/Core/OpenGL/OpenGLMeshStorage.h"
#include "glad/glad.h"

void OpenGLMeshStorage::Bind(std::shared_ptr<MeshAsset> mesh) {
    unsigned int index;
    if (meshes.find(mesh) == meshes.end()) 
        index = this->CompileMesh(mesh);
    else
        index = meshes[mesh];
    glBindVertexArray(index);
}

unsigned int OpenGLMeshStorage::CompileMesh(var<MeshAsset> mesh) {
    return 0;
}
