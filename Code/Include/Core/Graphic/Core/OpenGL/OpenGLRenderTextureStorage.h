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
    void PutTemporary(var<RenderTexture>& renderTexture);
    void Bind(const var<RenderTexture>& renderTexture);
    void Release();
private:
    var<RenderTexture> CreateRT(const RenderTextureDescribe& describe);
    void DestroyRT(unsigned int fbo);
private:
    std::unordered_map<RenderTextureDescribe, var<RenderTexture>, RenderTextureHash> renderTextures;
    std::unordered_map<var<RenderTexture>, unsigned int> renderTextureMap;
};


#endif //CODE_OPENGLRENDERTEXTURESTORAGE_H
