//
// Created by Administrator on 2023/9/25.
//

#include "GlobalSetting.h"

REFLECT_REGISTER(GlobalSetting) /* NOLINT */

GraphicType GlobalSetting::graphicType;
int GlobalSetting::windowWidth, GlobalSetting::windowHeight;

void GlobalSetting::SerializeInInternal(inputArchive &archive) {
    archive(graphicType, windowWidth, windowHeight);
}

void GlobalSetting::SerializeOutInternal(outputArchive &archive) {
    archive(graphicType, windowWidth, windowHeight);
}