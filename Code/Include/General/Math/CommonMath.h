//
// Created by Administrator on 2023/10/17.
//

#ifndef CODE_COMMONMATH_H
#define CODE_COMMONMATH_H

#include "SerializePtr.h"

class CommonMath {
public:
    static float Saturate(float x, float min, float max);

    static int Saturate(int x, int min, int max);

public:
    struct Float2 {
    public:
        float info[2];
        void serialize(inputArchive &archive);
        void serialize(outputArchive &archive);
    };
    struct Float3 {
    public:
        float info[3];
        void serialize(inputArchive &archive);
        void serialize(outputArchive &archive);
    };
    struct Float4 {
    public:
        float info[4];
        void serialize(inputArchive &archive);
        void serialize(outputArchive &archive);
    };
};


#endif //CODE_COMMONMATH_H
