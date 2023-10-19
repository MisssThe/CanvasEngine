//
// Created by Administrator on 2023/9/25.
//

#include "../Include/Core/Graphic/Assets/MeshAsset.h"

REFLECT_REGISTER(MeshAsset) /* NOLINT */

//std::vector<float> position;
//std::vector<float> color;
//std::vector<float> normal;
//std::vector<float> tangent;
//std::vector<float> texCoord1;
//std::vector<float> texCoord2;
//std::vector<float> texCoord3;
//std::vector<unsigned int> face;

void MeshAsset::SerializeInInternal(inputArchive &archive) {
    archive(position, color, normal, texCoord1, face);
    this->indexCount = (int) face.size();
    this->vertexCount = (int) position.size();
}

void MeshAsset::SerializeOutInternal(outputArchive &archive) {
    archive(position, color, normal, texCoord1, face);
}

void MeshAsset::Clear() {
    position.clear();
    color.clear();
    normal.clear();
//    tangent.clear();
    texCoord1.clear();
    face.clear();
}

int MeshAsset::AllCount() {
    return (int)(this->position.size() + this->color.size() + this->normal.size() + this->texCoord1.size());
}
