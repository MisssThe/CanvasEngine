//
// Created by Administrator on 2023/10/17.
// 对Render Texture作缓存
// 暂时不开放创建静态Render Texture的接口
//

#ifndef CODE_OPENGLRENDERTEXTURESTORAGE_H
#define CODE_OPENGLRENDERTEXTURESTORAGE_H

#include "../RenderTexture.h"

class OpenGLRenderTextureStorage {
public:
    var<RenderTexture> GetTemporary(RenderTextureDescribe describe);
    var<RenderTexture> GetTemporary(unsigned int width, unsigned int height, unsigned int depth, ColorFormat format);
    var<RenderTexture> GetTemporary(unsigned int width, unsigned int height);
    var<RenderTexture> GetTemporary(unsigned int width, unsigned int height, unsigned int depth);
    void PutTemporary(var<RenderTexture>& renderTexture);
    void Bind(const var<RenderTexture>& renderTexture);
    void Release();
private:
    var<RenderTexture> CreateRT(unsigned int width, unsigned int height, unsigned int depth, ColorFormat format);
    void DestroyRT(unsigned int fbo);
private:
    std::unordered_map<RenderTextureDescribe, var<RenderTexture>, RenderTextureHash> renderTextures;
    std::unordered_map<var<RenderTexture>, unsigned int> renderTextureMap;
};


#endif //CODE_OPENGLRENDERTEXTURESTORAGE_H
