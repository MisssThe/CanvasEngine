//
// Created by Administrator on 2023/9/14.
//

#ifndef CODE_QUEUE_H
#define CODE_QUEUE_H

#include <queue>
#include <functional>

class Queue {
public:
    template<class T> static void Iterator(std::queue<T>& q, const std::function<void(T&)>& call)
    {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto t = q.front();
            call(t);
            q.push(t);
            q.pop();
        }
    }
    template<class T> static void IteratorRemove(std::queue<T>& q, const std::function<void(T&)>& call)
    {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto t = q.front();
            call(t);
            q.pop();
        }
    }

    //call返回为false时移除元素
    template<class T> static void IteratorRemoveBool(std::queue<T>& q, const std::function<bool(T&)>& call)
    {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto t = q.front();
            if (call(t))
                q.push(t);
            q.pop();
        }
    }
};


#endif //CODE_QUEUE_H
