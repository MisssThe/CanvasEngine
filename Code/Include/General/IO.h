//
// Created by Administrator on 2023/10/7.
//

#ifndef CODE_IO_H
#define CODE_IO_H

#include <string>

class IO {
public:
    static long long FileFinalModifyTime(const std::string& path);
    static std::string ExtendName(const std::string& path);
    static std::string FileName(const std::string& path);
    static bool Exist(const std::string& path);
};


#endif //CODE_IO_H
