//
// Created by Administrator on 2023/9/13.
//

#ifndef CODE_CUSTOMPTR_H
#define CODE_CUSTOMPTR_H

#include <memory>
#include <functional>
#include <string>

#define new_ptr std::make_shared
#define var std::shared_ptr
#define class_var std::weak_ptr
#define cast std::static_pointer_cast
#define safe_cast std::dynamic_pointer_cast

class CustomPtr {
public:
    virtual std::string Type() = 0;
};

class Reflect {
private:
    static std::unordered_map<std::string, std::function<var<CustomPtr>()>> reflectMap;
public:
    static std::shared_ptr<CustomPtr> Instance(const std::string& type);
    static bool Register(const std::string& type, const std::function<std::shared_ptr<CustomPtr>()>& call);
};

#define REFLECT_REGISTER(Type) bool Type##Register = Reflect::Register(#Type, []()->std::shared_ptr<CustomPtr> { return std::static_pointer_cast<CustomPtr>(std::make_shared<Type>()); })

#endif //CODE_CUSTOMPTR_H
