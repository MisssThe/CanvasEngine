//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_MESHASSET_H
#define CODE_MESHASSET_H

#include "Assets/CustomAsset.h"

class MeshAsset : public CustomAsset {
public:
    std::string Type() override;
    ~MeshAsset() override = default;
public:
    void Cache(std::string_view file) override;
    int Size() const;
private:
    void LoadMesh(const std::string_view& file);
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
public:
    std::vector<unsigned int> indices;
    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> tangents;
    std::vector<float> colors;
    std::vector<float> uv0s;
    std::vector<float> uv1s;
    std::vector<float> uv2s;
private:
    int memorySize;
};


#endif //CODE_MESHASSET_H
