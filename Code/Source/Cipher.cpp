//
// Created by Administrator on 2023/9/14.
//

#include <combaseapi.h>
#include <iostream>
#include "../Include/General/Cipher.h"

std::string Cipher::Guid() {
    _GUID guid;
    CoCreateGuid(&guid);
    return std::to_string(guid.Data1) + std::to_string(guid.Data2) + std::to_string(guid.Data3) + std::string(reinterpret_cast<const char *>(guid.Data4));
}
