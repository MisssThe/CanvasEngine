//
// Created by Insomnia on 2023/9/14.
//

#ifndef CODE_TIME_H
#define CODE_TIME_H

#include <string>
#include <functional>

class Time final {
private:
    Time() = default;
private:
    static unsigned long  long int begin;
    static unsigned long  long int now;
    static unsigned long  long int last;
    static unsigned long  long int frame;
public:
    static unsigned long  long int SystemTime();                               //系统时间
    static unsigned long  long int CanvasTime();                               //程序运行时间
    static std::string CanvasTimeWithStr();                              //程序运行时间(输出格式（时：分：秒：毫秒）)
    static std::string CanvasTimeToStr(unsigned long long int time);          //程序运行时间(输出格式（时：分：秒：毫秒）)
    static unsigned long long int UseTime(std::function<void()> func);        //function执行时间
    static unsigned long  long int FrameTime();                                //上一帧花费时间
public:
    static void UpdateFrame();                                           //刷新帧间隔时间
};

#endif //CODE_TIME_H
