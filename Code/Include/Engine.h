//
// Created by Insomnia on 2023/9/14.
// 负责整个系统的资源初始化、卸载
// 注意全局数据的释放
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
    bool IsExist() const;
private:
    void* operator new(size_t size);
    void operator delete(void* p);
private:
    static std::queue<std::function<bool()>> closes;
    bool isExist;
};


#endif //CODE_ENGINE_H
