//
// Created by Administrator on 2023/10/17.
//

#ifndef CODE_COLOR_H
#define CODE_COLOR_H

#include "SerializePtr.h"
#include "CustomValue.h"

class Color : public SerializePtr, public CustomValue {
public:
    void SetColor(int inR, int gIN, int bIN, int aIN);
    int R();
    int G();
    int B();
    int A();
    float r();
    float g();
    float b();
    float a();
private:
    int color[4];
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
};


#endif //CODE_COLOR_H
