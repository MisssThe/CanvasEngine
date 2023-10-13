//
// Created by Administrator on 2023/10/7.
//
#include "../Include/Core/Graphic/AssetsLoader/MeshLoader.h"
#include "Assets/AssetManager.h"
#include "../Include/General/IO.h"
#include "../Include/General/String.h"
#include <map>


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
    meshAsset->Clear();
    int group = -1;
    std::map<Vector3, unsigned int> temp;
    int index = 0;
    Vector3 vector3;
    IO::ReadFilePerLine(path, [&meshAsset, &result, &face, &group, &temp, &index, &vector3](std::string& info) {
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
            case 234:   //texCoord
                for (unsigned int i = 1; i < 5 && i < size ; ++i) {
                    meshAsset->texCoord1.push_back(std::stof(result[i]));
                }
                break;
            case 134:   //face
                for (unsigned int i = 1; i < 4 && i < size ; ++i) {
                    String::Split(result[i],'/',face);
                    group = (int)face.size();
                    for (unsigned int j = 0; j < 3 && j < face.size(); ++j) {
                        vector3.info[j] = std::stoi(face[j]);
                    }
                    if (temp.find(vector3) == temp.end()) {
                        temp.insert(std::pair<Vector3, unsigned int>(vector3, index++));
                        //添加position和color
                        int positionIndex = vector3.info[0] * 3;
                        meshAsset->compactnessInfo.push_back(meshAsset->position[positionIndex]);
                        meshAsset->compactnessInfo.push_back(meshAsset->position[positionIndex + 1]);
                        meshAsset->compactnessInfo.push_back(meshAsset->position[positionIndex + 2]);
                        if (!meshAsset->color.empty()) {
                            meshAsset->compactnessInfo.push_back(meshAsset->color[positionIndex + 2]);
                            meshAsset->compactnessInfo.push_back(meshAsset->color[positionIndex + 2]);
                            meshAsset->compactnessInfo.push_back(meshAsset->color[positionIndex + 2]);
                        }
                        //添加法线
                        if (!meshAsset->normal.empty()) {
                            int normalIndex = vector3.info[1] * 3;
                            meshAsset->compactnessInfo.push_back(meshAsset->normal[normalIndex]);
                            meshAsset->compactnessInfo.push_back(meshAsset->normal[normalIndex + 1]);
                            meshAsset->compactnessInfo.push_back(meshAsset->normal[normalIndex + 2]);
                        }
                        //添加纹理坐标
                        if (!meshAsset->texCoord1.empty()) {
                            int texCoordIndex = vector3.info[1] * 3;
                            meshAsset->compactnessInfo.push_back(meshAsset->texCoord1[texCoordIndex]);
                            meshAsset->compactnessInfo.push_back(meshAsset->texCoord1[texCoordIndex + 1]);
                            meshAsset->compactnessInfo.push_back(meshAsset->texCoord1[texCoordIndex + 2]);
                        }
                    }
                    meshAsset->face.push_back(temp[vector3]);
                }
                break;
            default:
                return;
        }
    });
    //填充完数据后对数据进行调整优化
    //step1:去除重复点
}
