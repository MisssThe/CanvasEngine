//
// Created by Administrator on 2023/10/17.
//

#include "../Include/General/Math/CommonMath.h"

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

void CommonMath::Float2::serialize(inputArchive &archive) {
    archive(this->info[0], this->info[1]);
}

void CommonMath::Float2::serialize(outputArchive &archive) {
    archive(this->info[0], this->info[1]);
}

void CommonMath::Float3::serialize(inputArchive &archive) {
    archive(this->info[0], this->info[1], this->info[2]);
}

void CommonMath::Float3::serialize(outputArchive &archive) {
    archive(this->info[0], this->info[1], this->info[2]);
}

void CommonMath::Float4::serialize(inputArchive &archive) {
    archive(this->info[0], this->info[1], this->info[2], this->info[3]);
}

void CommonMath::Float4::serialize(outputArchive &archive) {
    archive(this->info[0], this->info[1], this->info[2], this->info[3]);
}