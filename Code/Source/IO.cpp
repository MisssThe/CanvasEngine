//
// Created by Administrator on 2023/10/7.
//

#include "../Include/General/IO.h"
#include <chrono>
#include <filesystem>
#include <fstream>

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
    return path.substr(position+1, end - position - 1);
}

bool IO::Exist(const std::string& path) {
    return std::filesystem::exists(path);
}

bool IO::IsDirectory(const std::string &path) {
    std::ifstream is(path);
    bool flag = !is.is_open();
    is.close();
    return flag;
}

void IO::ReadFileAsString(const std::string &path, std::string &info) {
    std::ifstream is(path);
    if (!is.is_open()) {
        return;
    }
    std::stringstream ss;
    ss << is.rdbuf();
    info = ss.str();
    is.close();
}

void IO::ReadFilePerLine(const std::string &path, std::function<void(std::string&)> call) {
    std::ifstream is(path, std::ios::in);
    if(!is.is_open())
        return;
    std::string strLine;
    while(getline(is, strLine))
    {
        if(strLine.empty())
            continue;
        call(strLine);
    }
    is.close();
}
