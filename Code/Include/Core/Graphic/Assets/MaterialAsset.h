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
    enum DepthTestMode {
        LEqual,
    };
    enum BlendMode {
        Opaque,
        Transparent,
    };
    enum CullMode {
        Front,      //保留正面
        Back,       //保留背面
        Both        //两面都保留
    };
    enum InfoMode
    {
        Vec1, Vec2, Vec3, Vec4, Texture2D
    };
public:
    void BindShader(var<ShaderAsset>& shaderAsset);
    void AddTexture(const std::string& name, const std::string& texture);
    void AddVector(const std::string& name, float x, float y, float z, float w, InfoMode mode);
public:
    struct MaterialInfo
    {
    public:
        std::string key;
        InfoMode flag;
        float info[4];
        var<TextureAsset> texture;
        void serialize(inputArchive &archive);
        void serialize(outputArchive &archive);
    };
    std::unordered_map<std::string, MaterialInfo> properties;
    var<ShaderAsset> shader;
    DepthTestMode depthTest = LEqual;
    bool depthWrite = true;
    BlendMode blend = Opaque;
    CullMode cull = Front;
};


#endif //CODE_MATERIALASSET_H
