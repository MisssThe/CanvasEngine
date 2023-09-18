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
    static unsigned long int begin;
    static unsigned long int now;
    static unsigned long int last;
    static unsigned long int frame;
public:
    static unsigned long int CanvasTime();                               //程序运行时间
    static std::string CanvasTimeWithStr();                              //程序运行时间(输出格式（时：分：秒：毫秒）)
    static std::string CanvasTimeToStr(unsigned long int time);          //程序运行时间(输出格式（时：分：秒：毫秒）)
    static unsigned long int UseTime(std::function<void()> func);        //function执行时间
    static unsigned long int FrameTime();                                //上一帧花费时间
public:
    static void UpdateFrame();                                           //刷新帧间隔时间
};

#endif //CODE_TIME_H
