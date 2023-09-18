//
// Created by Insomnia on 2023/9/14.
//

#ifndef CODE_DEBUG_H
#define CODE_DEBUG_H

#include <string>

class Debug {
public:
    static void Info(const std::string& context, const std::string& title = "");
};


#endif //CODE_DEBUG_H
