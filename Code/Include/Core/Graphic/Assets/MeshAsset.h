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
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
};


#endif //CODE_MESHASSET_H
