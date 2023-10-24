//
// Created by Administrator on 2023/10/13.
//

#include "../Include/Core/Graphic/Core/OpenGL/OpenGLMeshStorage.h"
#include "glad/glad.h"
#include "../Include/General/Container/Queue.h"
#include "../Include/General/Container/Map.h"
#include "../Include/General/Tool/Debug.h"

void OpenGLMeshStorage::Bind(std::shared_ptr<MeshAsset> mesh) {
    unsigned int index;
    if (meshes.find(mesh) == meshes.end()) {
        index = this->CompileMesh(mesh);
    }
    else
        index = meshes[mesh];
    glBindVertexArray(index);
}

void OpenGLMeshStorage::Release() {
    for (auto a : this->meshes) {
        glDeleteVertexArrays(1, &a.second);
    }
    Queue::IteratorRemove<unsigned int>(this->buffers,[](unsigned int b) {
        glDeleteBuffers(1, &b);
    });
}

int OpenGLMeshStorage::SubVertexBuffer(long long int offset, std::vector<float> &buffer, int index, int stride) {
    if (buffer.empty())
        return 0;
    int size = (int) (sizeof(float) * buffer.size());
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, &buffer[0]);
    glVertexAttribPointer(index, stride, GL_FLOAT, GL_FALSE, stride * (int)sizeof(float), (void *) offset);
    glEnableVertexAttribArray(index);
    return size;
}

unsigned int OpenGLMeshStorage::CompileMesh(var<MeshAsset>& mesh) {
    unsigned int vao;
    unsigned int vbo, ebo;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (int)(sizeof(float) * mesh->face.size()), &mesh->face[0], GL_STATIC_DRAW);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (int)(sizeof(indices)), indices, GL_STATIC_DRAW);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, (int)(sizeof(float) * mesh->AllCount()), nullptr, GL_STATIC_DRAW);

    int offset = 0;
    offset += this->SubVertexBuffer(offset, mesh->position, 0, 3);
    offset += this->SubVertexBuffer(offset, mesh->color, 1, 4);
    offset += this->SubVertexBuffer(offset, mesh->normal, 2, 3);
//    offset += this->SubVertexBuffer(offset, mesh->tangent, 2, 4);
    offset += this->SubVertexBuffer(offset, mesh->texCoord1, 3, 2);
//    offset += this->SubVertexBuffer(offset, mesh->texCoord2, 5, 2);
//    offset += this->SubVertexBuffer(offset, mesh->texCoord3, 6, 2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    if (offset < 1) {
        glDeleteVertexArrays(1, &vao);
        Debug::Warn("OpenGL Mesh Compile", "Compile Failed [" + mesh->path + "]");
        return -1;
    }
    Map::Insert(this->meshes, mesh, vao);
    return vao;
}