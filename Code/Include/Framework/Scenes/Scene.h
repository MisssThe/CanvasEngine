//
// Created by Insomnia on 2023/9/14.
//

#ifndef CODE_SCENE_H
#define CODE_SCENE_H



#include "Assets/CustomAsset.h"

class Scene : public CustomAsset {
public:
    std::string Type() override;
    ~Scene() override = default;

protected:
    void SerializeInInternal(cereal::BinaryInputArchive &archive) override;

    void SerializeOutInternal(cereal::BinaryOutputArchive &archive) override;
};


#endif //CODE_SCENE_H
