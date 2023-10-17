//
// Created by Administrator on 2023/10/12.
//

#include <sstream>
#include <iostream>
#include "../Include/General/Tool/String.h"

void String::Split(std::string &source, char split, std::vector<std::string> &result) {
    result.clear();
    std::istringstream iss(source);
    std::string token;
    while (getline(iss, token, split))
    {
        if (token.empty())
            continue;
        result.push_back(token);
    }
}

void String::ToLower(std::string &source) {
    for (unsigned int i = 0; i < source.size(); ++i) {
        unsigned short int c = source[i];
        if (c > 64 && c < 91)
            source[i] = c + 32;
    }
}
