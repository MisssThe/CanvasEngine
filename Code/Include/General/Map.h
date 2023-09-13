//
// Created by Administrator on 2023/9/13.
//

#ifndef CODE_MAP_H
#define CODE_MAP_H

#include <unordered_map>

class Map {
public:
    template<class A, class B> static void Insert(std::unordered_map<A, B>& map, A a, B b) {
        map.insert(std::pair<A,B>(a, b));
    }
};

#endif //CODE_MAP_H
