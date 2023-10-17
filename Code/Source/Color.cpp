//
// Created by Administrator on 2023/10/17.
//

#include "../Include/General/Math/Color.h"
#include "../Include/General/Math/CommonMath.h"

void Color::SerializeInInternal(inputArchive &archive) {
    archive(this->color[0], this->color[1], this->color[2], this->color[3]);
}

void Color::SerializeOutInternal(outputArchive &archive) {
    archive(this->color[0], this->color[1], this->color[2], this->color[3]);
}

void Color::SetColor(int rIN, int gIN, int bIN, int aIN) {
    this->color[0] = CommonMath::Saturate(rIN, 0, 255);
    this->color[1] = CommonMath::Saturate(gIN, 0, 255);
    this->color[2] = CommonMath::Saturate(bIN, 0, 255);
    this->color[3] = CommonMath::Saturate(aIN, 0, 255);
}

int Color::R() {
    return this->color[0];
}

int Color::G() {
    return this->color[1];
}

int Color::B() {
    return this->color[2];
}

int Color::A() {
    return this->color[3];
}

float Color::r() {
    return ((float)this->color[0]) / 255.0f;
}

float Color::g() {
    return ((float)this->color[1]) / 255.0f;
}

float Color::b() {
    return ((float)this->color[2]) / 255.0f;
}

float Color::a() {
    return ((float) this->color[3]) / 255.0f;
}