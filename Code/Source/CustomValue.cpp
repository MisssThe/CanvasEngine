//
// Created by Administrator on 2023/10/17.
//

#include "CustomValue.h"

void CustomValue::operator delete(void *p) {

}

void *CustomValue::operator new(size_t t) {
    return (void *)(1);
}
