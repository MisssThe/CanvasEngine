//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_MESHASSET_H
#define CODE_MESHASSET_H

#include "Assets/CustomAsset.h"
#include <cereal/types/vector.hpp>

class MeshAsset : public CustomAsset {
public:
    std::string Type() override;
    ~MeshAsset() override = default;
    void Clear();
    int AllCount();
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
public:
    std::vector<float> position;
    std::vector<float> color;
    std::vector<float> normal;
//    std::vector<float> tangent;
    std::vector<float> texCoord1;
//    std::vector<float> texCoord2;
//    std::vector<float> texCoord3;
    std::vector<unsigned int> face;
public:
    int indexCount;
    int vertexCount;
};


#endif //CODE_MESHASSET_H
