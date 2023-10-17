//
// Created by Administrator on 2023/9/14.
//

#include "../Include/General/Tool/Cipher.h"
#include "../Include/General/Tool/Time.h"
#include <random>

//std::default_random_engine Cipher::dre(Time::SystemTime() + std::stoi(Mac()));
//
//std::string Cipher::Mac() {
//    return std::to_string(20010116);
//}
//
//Cipher::GUID Cipher::Guid() {
//    std::uniform_int_distribution uid(-127, 128);
//    GUID guid;
//    for (int i = 0; i < 16; ++i) {
//        guid.id[i] = (char)uid(dre);
//    }
//    return guid;
//}