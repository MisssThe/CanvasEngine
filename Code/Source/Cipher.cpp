//
// Created by Administrator on 2023/9/14.
//

#include <combaseapi.h>
#include "../Include/General/Cipher.h"

std::string Cipher::Guid() {
    _GUID guid{};
    CoCreateGuid(&guid);
    int index = 0;
    char data[16];
    for (int offset = 0; offset < 4; ++offset) {
        data[index++] = guid.Data1 >> (offset * 4);
    }
    for (int offset = 0; offset < 2; ++offset) {
        data[index++] = guid.Data2 >> (offset * 4);
    }
    for (int offset = 0; offset < 2; ++offset) {
        data[index++] = guid.Data3 >> (offset * 4);
    }
    for (int offset = 0; offset < 8; ++offset) {
        data[index++] = guid.Data4[offset];
    }
    return {data};
}
