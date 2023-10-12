//
// Created by Administrator on 2023/10/7.
//

#include "../Include/Core/Graphic/AssetsLoader/MeshLoader.h"
#include "Assets/AssetManager.h"
#include "../Include/General/IO.h"
#include "../Include/General/String.h"

bool MeshRegister = AssetManager::RegisterRefresh([](std::string& path) {
    if (path.find("Assets\\Mesh") == std::string::npos)
        return;
    MeshLoader::Load(path);
});

void MeshLoader::Load(const std::string &path) {
    std::string extension = IO::ExtendName(path);
    String::ToLower(extension);
    std::string name = IO::FileName(path);
    std::string newPath = "Caches/Mesh/" + name + ".mesh";
    var<MeshAsset> meshAsset;
    if (IO::Exist(newPath))
        meshAsset = safe_cast<MeshAsset>(AssetManager::Instance(newPath));
    else {
        meshAsset = new_ptr<MeshAsset>();
        AssetManager::Create(newPath, meshAsset);
    }

    if (extension == "obj")
        LoadOBJ(path, meshAsset);
}

//Obj格式 顶点、顶点色、法线、一套纹理坐标、索引
void MeshLoader::LoadOBJ(const std::string &path, std::shared_ptr<MeshAsset> meshAsset) {
    //解析mesh info
    std::vector<std::string> result(6);
    std::vector<std::string> face(3);
    IO::ReadFilePerLine(path, [&meshAsset, &result, &face](std::string& info) {
        //判断数据类型
        unsigned short int infoType = (unsigned short int)info[0] + (unsigned short int)info[1];
        String::Split(info, ' ', result);
        unsigned int size = result.size();
        switch (infoType) {
            case 150:   //vertex
            {
                for (unsigned int i = 1; i < 4 && i < size ; ++i) {
                    meshAsset->position.push_back(std::stof(result[i]));
                }
                for (unsigned int i = 4; i < size; ++i) {
                    meshAsset->color.push_back(std::stof(result[i]));
                }
            }
                break;
            case 228:   //normal
                for (unsigned int i = 1; i < 4 && i < size ; ++i) {
                    meshAsset->normal.push_back(std::stof(result[i]));
                }
                break;
            case 234:   //texcoord
                for (unsigned int i = 1; i < 5 && i < size ; ++i) {
                    meshAsset->texCoord1.push_back(std::stof(result[i]));
                }
                break;
            case 134:   //face
                for (unsigned int i = 1; i < 4 && i < size ; ++i) {
                    String::Split(result[i],'/',face);
                    for (unsigned int j = 0; j < 3 && j < face.size(); ++j) {
                        meshAsset->face.push_back(std::stoi(result[i]));
                    }
                }
                break;
            default:
                return;
        }
    });
}
