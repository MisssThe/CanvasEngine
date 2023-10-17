//
// Created by Administrator on 2023/10/17.
//

#ifndef CODE_OPENGLTEXTURESTORAGE_H
#define CODE_OPENGLTEXTURESTORAGE_H


#include "CustomPtr.h"
//#include "Assets/CustomAsset.h"
//#include "CustomEntity.h"

class OpenGLTextureStorage : public CustomPtr {
//class OpenGLTextureStorage : public CustomAsset {
//class OpenGLTextureStorage : public CustomEntity {
public:
    std::string Type() override;

    ~OpenGLTextureStorage() override = default;
};


#endif //CODE_OPENGLTEXTURESTORAGE_H
