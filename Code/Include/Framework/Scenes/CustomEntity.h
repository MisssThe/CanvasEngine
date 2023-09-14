//
// Created by Insomnia on 2023/9/14.
//

#ifndef CODE_CUSTOMENTITY_H
#define CODE_CUSTOMENTITY_H

#include "CustomPtr.h"

class CustomEntity : public CustomPtr {
public:
    std::string Type() override;
    ~CustomEntity() override = default;

};


#endif //CODE_CUSTOMENTITY_H
