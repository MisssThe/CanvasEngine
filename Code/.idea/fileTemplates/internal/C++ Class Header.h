#parse("C File Header.h")
#[[#ifndef]]# ${INCLUDE_GUARD}
#[[#define]]# ${INCLUDE_GUARD}

${NAMESPACES_OPEN}

#[[#include]]# "CustomPtr.h"
//#[[#include]]# "Assets/CustomAsset.h"
//#[[#include]]# "CustomEntity.h"

class ${NAME} : public CustomPtr {
//class ${NAME} : public CustomAsset {
//class ${NAME} : public CustomEntity {

};

${NAMESPACES_CLOSE}

#[[#endif]]# //${INCLUDE_GUARD}
