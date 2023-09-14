//
// Created by Insomnia on 2023/9/14.
//

#include <iostream>
#include "../Include/General/Debug.h"

void Debug::LogInfo(const std::string &context, const std::string& title) {
    std::cout << "[" << title << "]: " << context << std::endl;
}
