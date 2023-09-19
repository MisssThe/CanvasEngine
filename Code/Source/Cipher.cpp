//
// Created by Administrator on 2023/9/14.
//

#include "../Include/General/Cipher.h"
#include "../Include/General/Time.h"
#include <random>

std::default_random_engine Cipher::dre(Time::SystemTime() + std::stoi(Mac()));

std::string Cipher::Mac() {
    return std::to_string(20010116);
}

Cipher::GUID Cipher::Guid() {
    std::uniform_int_distribution uid(-2147483640, 2147483640);
    GUID guid;
    guid.id1 = uid(dre);
    guid.id2 = uid(dre);
    guid.id3 = uid(dre);
    guid.id4 = uid(dre);
    return guid;
}

void Cipher::GUID::serialize(cereal::BinaryInputArchive &archive) {
    archive(this->id1, this->id2, this->id3, this->id4);
}

void Cipher::GUID::serialize(cereal::BinaryOutputArchive &archive) {
    archive(this->id1, this->id2, this->id3, this->id4);
}

bool Cipher::GUID::operator==(const Cipher::GUID &n) const {
    return n.id1 == this->id1 && n.id2 == this->id2 && n.id3 == this->id3 && n.id4 == this->id4;
}

bool Cipher::GUID::operator<(const Cipher::GUID &c) const {
    return c.id1 < this->id1 && c.id2 < this->id2 && c.id3 < this->id3 && c.id4 < this->id4;
}

std::string Cipher::GUID::ToString() const {
    return std::to_string(this->id1) + std::to_string(this->id2) + std::to_string(this->id3) + std::to_string(this->id4);
}