//
// Created by MisThe on 2023/9/24.
//

#ifndef CODE_TESTASSET_H
#define CODE_TESTASSET_H


#include "Assets/CustomAsset.h"

class TestAsset : public CustomAsset {
public:
    char guid[16];
public:
    std::string Type() override;
    ~TestAsset() override = default;

protected:
    void SerializeInInternal(inputArchive &archive) override;

    void SerializeOutInternal(outputArchive &archive) override;
};


#endif //CODE_TESTASSET_H
