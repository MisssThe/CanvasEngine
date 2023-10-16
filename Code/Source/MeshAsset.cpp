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
    archive(position, color, normal, tangent, texCoord1, texCoord2, texCoord3, face, this->compactnessInfo);
    this->indexCount = (int)face.size();
    this->vertexCount = (int)position.size();
}

void MeshAsset::SerializeOutInternal(outputArchive &archive) {
    archive(position, color, normal, tangent, texCoord1, texCoord2, texCoord3, face, this->compactnessInfo);
}

void MeshAsset::Clear() {
    position.clear();
    color.clear();
    normal.clear();
    tangent.clear();
    texCoord1.clear();
    texCoord2.clear();
    texCoord3.clear();
    face.clear();
}
