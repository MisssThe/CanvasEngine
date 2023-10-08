//
// Created by Administrator on 2023/10/7.
//

#include "Assets/AssetLog.h"
#include "../Include/General/IO.h"
#include <cereal/types/unordered_map.hpp>

REFLECT_REGISTER(AssetLog) /* NOLINT */

void AssetLog::SerializeInInternal(inputArchive &archive) {
    archive(this->info);
}

void AssetLog::SerializeOutInternal(outputArchive &archive) {
    archive(this->info);
}

bool AssetLog::Replace(const std::string& path) {
    unsigned long long time = IO::FileFinalModifyTime(path);
    auto f = this->info.find(path);
    if (f == this->info.end()) {
        this->info.insert(std::pair<std::string, unsigned long long int>(path, time));
        return true;
    }
    if (f->second != time) {
        this->info[path] = time;
        return true;
    }
    return true;
}
