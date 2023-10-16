//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_MATERIALASSET_H
#define CODE_MATERIALASSET_H

#include "Assets/CustomAsset.h"
#include "ShaderAsset.h"
#include "TextureAsset.h"

class MaterialAsset : public CustomAsset {
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
public:
    std::string Type() override;
    ~MaterialAsset() override = default;
public:
    struct MaterialInfo
    {
    public:
        bool flag;
        float info[4];
        var<TextureAsset> texture;
        void serialize(inputArchive &archive);
        void serialize(outputArchive &archive);
    };
    std::unordered_map<std::string, MaterialInfo> properties;
    var<ShaderAsset> shader;
    bool depthTest = true;
    bool depthWrite = true;
};


#endif //CODE_MATERIALASSET_H
