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
        std::string ToString() const;
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

template<class T> class GuidMap {
private:
    std::unordered_map<std::string ,T> map;
public:
    void Insert(Cipher::GUID &guid, T &t) {
        std::string key = guid.ToString();
        this->map.insert(std::pair<std::string , T>(key, t));
    }

    T Find(Cipher::GUID &guid) {
        auto result = this->map.find(guid.ToString());
        if (result == this->map.end())
            return nullptr;
        return result->second;
    }
};

#endif //CODE_CIPHER_H
