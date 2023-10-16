//
// Created by Administrator on 2023/10/13.
//

#include "../Include/Core/Graphic/Core/OpenGL/OpenGLMeshStorage.h"
#include "glad/glad.h"
#include "../Include/General/Queue.h"

void OpenGLMeshStorage::Bind(std::shared_ptr<MeshAsset> mesh) {
    unsigned int index;
    if (meshes.find(mesh) == meshes.end()) {
        index = this->CompileMesh(mesh);
    }
    else
        index = meshes[mesh];
    glBindVertexArray(index);
}

unsigned int OpenGLMeshStorage::CompileMesh(var<MeshAsset> mesh) {
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * mesh->compactnessInfo.size(), mesh->compactnessInfo.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * mesh->face.size(), mesh->face.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    this->meshes.insert(std::pair<var<MeshAsset>, unsigned int>( mesh, VAO));
    this->buffers.push(VBO);
    this->buffers.push(EBO);

    return VAO;
}

void OpenGLMeshStorage::Release() {
    for (auto a : this->meshes) {
        glDeleteVertexArrays(1, &a.second);
    }
    Queue::IteratorRemove<unsigned int>(this->buffers,[](unsigned int b) {
        glDeleteBuffers(1, &b);
    });
}
