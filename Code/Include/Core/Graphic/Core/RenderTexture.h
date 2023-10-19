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
    int width;
    int height;
    int depth;
    std::vector<ColorFormat> formats;
    bool operator==(const RenderTextureDescribe& rt) const {
        if (rt.formats.size() != this->formats.size())
            return false;
        for (unsigned int index = 0; index < this->formats.size(); ++index) {
            if (this->formats[index] == rt.formats[index])
                return false;
        }
        return rt.width == this->width
        && rt.height == this->height
        && rt.depth == this->depth;
    }
};

struct RenderTextureHash
{
public:
    std::size_t operator() (const RenderTextureDescribe & c) const
    {
        size_t seed = 0;
        CustomHash(seed, c.width);
        CustomHash(seed, c.height);
        CustomHash(seed, c.depth);
        for (auto f : c.formats) {
            CustomHash(seed, f);
        }
        return seed;
    }
private:
    void CustomHash(size_t& seed, const int& info)const
    {
        seed = std::hash<int>()(info) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
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