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
    struct GUID
    {
    public:
        GUID() = default;
        int id1{};
        int id2{};
        int id3{};
        int id4{};
        void serialize(cereal::BinaryInputArchive &archive);
        void serialize(cereal::BinaryOutputArchive &archive);
        bool operator==(const GUID &n) const;
        bool operator < (const GUID& c) const;
    };
public:
    static GUID Guid();
    static std::string Mac();
private:
    static std::default_random_engine dre;
};


#endif //CODE_CIPHER_H
