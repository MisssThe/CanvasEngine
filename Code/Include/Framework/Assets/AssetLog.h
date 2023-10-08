//
// Created by Administrator on 2023/10/7.
//

#ifndef CODE_ASSETLOG_H
#define CODE_ASSETLOG_H


#include "Assets/CustomAsset.h"

class AssetLog : public CustomAsset {
public:
    std::string Type() override;
    ~AssetLog() override = default;
    bool Replace(const std::string& path);
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
private:
    std::unordered_map<std::string, unsigned long long> info;
};


#endif //CODE_ASSETLOG_H
