//
// Created by Administrator on 2023/10/7.
//

#include "../Include/General/IO.h"
#include <chrono>
#include <filesystem>

long long IO::FileFinalModifyTime(const std::string& path) {
    auto epoch = std::filesystem::last_write_time(path).time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count();
}

std::string IO::ExtendName(const std::string &path) {
    return path.substr(path.find_last_of('.') + 1);;
}

std::string IO::FileName(const std::string& path) {
    size_t position = path.find_last_of("/\\");
    size_t end = path.find_last_of(".");
    return path.substr(position+1, end - position);
}

bool IO::Exist(const std::string& path) {
    return std::filesystem::exists(path);
}
