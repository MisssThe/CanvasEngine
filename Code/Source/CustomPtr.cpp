//
// Created by Administrator on 2023/9/13.
//

#include "../Include/Framework/CustomPtr.h"
#include "../Include/General/Map.h"

std::unordered_map<std::string, std::function<var<CustomPtr>()>> Reflect::reflectMap;

var<CustomPtr> Reflect::Instance(const std::string& type) {
    auto cp = reflectMap.find(type);
    if (cp == reflectMap.end())
        return nullptr;
    return cp->second();
}

bool Reflect::Register(const std::string &type, const std::function<std::shared_ptr<CustomPtr>()> &call) {
    Map::Insert(reflectMap, type, call);
    return true;
}

CustomPtr::~CustomPtr() = default;
