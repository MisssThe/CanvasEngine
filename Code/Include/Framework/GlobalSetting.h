//
// Created by Administrator on 2023/9/25.
//

#ifndef CODE_GLOBALSETTING_H
#define CODE_GLOBALSETTING_H

#include "Assets/CustomAsset.h"
#include "../Core/Graphic/Graphic.h"

class GlobalSetting : public CustomAsset {
public:
    std::string Type() override;
    ~GlobalSetting() override = default;
protected:
    void SerializeInInternal(inputArchive &archive) override;
    void SerializeOutInternal(outputArchive &archive) override;
public:
    //Graphic
    static GraphicType graphicType;
    static PipelineType pipelineType;
    static int windowWidth, windowHeight;
    static std::string windowName;
    static bool isVSync;
};


#endif //CODE_GLOBALSETTING_H
