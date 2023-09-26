//
// Created by Administrator on 2023/9/25.
//

#include "GlobalSetting.h"

REFLECT_REGISTER(GlobalSetting) /* NOLINT */

GraphicType GlobalSetting::graphicType;
PipelineType GlobalSetting::pipelineType;
int GlobalSetting::windowWidth, GlobalSetting::windowHeight;
std::string GlobalSetting::windowName;

void GlobalSetting::SerializeInInternal(inputArchive &archive) {
    archive(graphicType, pipelineType, windowWidth, windowHeight, windowName);
}

void GlobalSetting::SerializeOutInternal(outputArchive &archive) {
    archive(graphicType, pipelineType, windowWidth, windowHeight, windowName);
}