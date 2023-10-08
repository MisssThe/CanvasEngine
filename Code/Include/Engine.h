//
// Created by Insomnia on 2023/9/14.
// 负责整个系统的资源初始化、卸载
// 不允许在堆上开辟Engine避免内存泄露
//

#ifndef CODE_ENGINE_H
#define CODE_ENGINE_H


#include <cstdlib>
#include <functional>
#include <queue>

class Engine {
public:
    Engine();
    ~Engine();
    void Invoke();
    static void RegisterClose(const std::function<bool()>& call);
private:
    bool IsExist();
private:
    void* operator new(size_t size);
    void operator delete(void* p);
private:
    static std::queue<std::function<bool()>> closes;
};


#endif //CODE_ENGINE_H
