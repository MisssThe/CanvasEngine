//
// Created by Administrator on 2023/9/18.
//

#ifndef CODE_DEQUE_H
#define CODE_DEQUE_H

#include <deque>
#include <functional>

class Deque final {
public:
    //is clean 返回true时视为无效元素需要清除
    template<class T> static void ClearUp(std::deque<T>& q, const std::function<bool(T&)>& isClean) {
        unsigned int count = q.size();
        unsigned int last = count - 1;
        for (unsigned int index = 0; index < q.size(); ++index) {
            if (isClean(q[index]))
            {
                q[index] = q[last];
                q.pop_back();
            }
        }
    }
};


#endif //CODE_DEQUE_H
