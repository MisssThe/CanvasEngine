//
// Created by Administrator on 2023/10/17.
// 禁止在堆上开辟空间
//

#ifndef CODE_CUSTOMVALUE_H
#define CODE_CUSTOMVALUE_H

#include <cstdio>

class CustomValue {
private:
    void *operator new(size_t t);
    void operator delete(void *p);
};


#endif //CODE_CUSTOMVALUE_H
