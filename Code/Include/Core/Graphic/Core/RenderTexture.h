//
// Created by Administrator on 2023/10/17.
//

#ifndef CODE_RENDERTEXTURE_H
#define CODE_RENDERTEXTURE_H

#include <functional>
#include "CustomValue.h"
#include "CustomPtr.h"

enum ColorFormat
{
    RGBA32
};

struct RenderTextureDescribe : public CustomValue {
public:
    unsigned int width;
    unsigned int height;
    unsigned int depth; 
    ColorFormat format;
    bool operator==(const RenderTextureDescribe& rt) const {
        return rt.width == this->width && rt.height == this->height && rt.depth == this->depth && rt.format == this->format;
    }
};

struct RenderTextureHash
{
    std::size_t operator() (const RenderTextureDescribe & node) const {
        std::size_t h1 = std::hash<unsigned int>()(node.width);
        std::size_t h2 = std::hash<unsigned int>()(node.height);
        std::size_t h3 = std::hash<unsigned int>()(node.depth);
        std::size_t h4 = std::hash<unsigned int>()(node.format);
        return h1 ^ h2 ^ h3 ^ h4;
    }
};

class RenderTexture : public CustomPtr
{
public:
    bool IsAsset() final;
    std::string Type() override;
    ~RenderTexture() override = default;
public:
    std::string name;
    RenderTextureDescribe describe;
};

#endif //CODE_RENDERTEXTURE_H