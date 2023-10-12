//
// Created by Administrator on 2023/10/12.
//

#ifndef CODE_STRING_H
#define CODE_STRING_H


#include <string>
#include <vector>

class String {
public:
    static void Split(std::string& source, char split, std::vector<std::string>& result);
    static void ToLower(std::string& source);
};


#endif //CODE_STRING_H
