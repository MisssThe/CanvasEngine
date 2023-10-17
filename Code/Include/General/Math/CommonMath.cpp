//
// Created by Administrator on 2023/10/17.
//

#include "CommonMath.h"

float CommonMath::Saturate(float x, float min, float max) {
    if (x > max)
        return max;
    else if (x < min)
        return min;
    return x;
}

int CommonMath::Saturate(int x, int min, int max) {
    if (x > max)
        return max;
    else if (x < min)
        return min;
    return x;
}
