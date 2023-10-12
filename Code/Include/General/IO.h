//
// Created by Administrator on 2023/10/7.
//

#ifndef CODE_IO_H
#define CODE_IO_H

#include <string>
#include <functional>

class IO {
public:
    static long long FileFinalModifyTime(const std::string& path);
    static std::string ExtendName(const std::string& path);
    static std::string FileName(const std::string& path);
    static bool Exist(const std::string& path);
    static bool IsDirectory(const std::string& path);
    static void ReadFileAsString(const std::string& path, std::string& info);
    static void ReadFilePerLine(const std::string& path, std::function<void(std::string&)> call);
};


#endif //CODE_IO_H
