//
// Created by MisThe on 2023/9/19.
//

#ifndef CODE_RENDERER_H
#define CODE_RENDERER_H

#include "Scenes/Component.h"

class Renderer : public Component {
public:
    std::string Type() override;
    ~Renderer() override = default;
    void Initial() override;
    void Enable() override;
    void Invoke() override;
    void Disable() override;
    void Release() override;
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
public:

};


#endif //CODE_RENDERER_H
