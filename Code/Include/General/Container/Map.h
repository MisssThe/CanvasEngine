//
// Created by Administrator on 2023/9/13.
//

#ifndef CODE_MAP_H
#define CODE_MAP_H

#include <unordered_map>

class Map {
public:
    template<class A, class B> static void Insert(std::unordered_map<A, B>& map, const A& a, const B& b) {
        if (map.find(a) != map.end()) {
            map[a] = b;
            return;
        }
        map.insert(std::pair<A,B>(a, b));
    }

    template<class A, class B> static B Find(std::unordered_map<A, B>& map, const A& a) {
        auto f = map.find(a);
        if (f == map.end())
            return nullptr;
        return f->second;
    }
};

#endif //CODE_MAP_H
