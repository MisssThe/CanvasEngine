//
// Created by Administrator on 2023/10/7.
//

#ifndef CODE_MESHLOADER_H
#define CODE_MESHLOADER_H

#include <string>
#include "../Assets/MeshAsset.h"

class MeshLoader  {
public:
    static void Load(const std::string& path);
private:
    struct Vector3
    {
    public:
        int info[3];
        bool operator < (const Vector3& v3) const
        {
            return this->info[0] < v3.info[0] || this->info[1] < v3.info[1] || this->info[2] < v3.info[2];
        }
    };
    static void LoadOBJ(const std::string& path, var<MeshAsset> meshAsset);
};


#endif //CODE_MESHLOADER_H
