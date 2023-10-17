//
// Created by Administrator on 2023/9/14.
// 封装各加/解密、压缩算法
//

#ifndef CODE_CIPHER_H
#define CODE_CIPHER_H

#include <string>
#include <random>
#include "cereal/archives/binary.hpp"

class Cipher {
public:
//    struct GUID
//    {
//    public:
//        char id[16];
//    };
public:
//    static GUID Guid();
//    static std::string Mac();
private:
    static std::default_random_engine dre;
};

#endif //CODE_CIPHER_H
