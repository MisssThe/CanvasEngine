//
// Created by Administrator on 2023/10/7.
//
#include "../Include/Core/Graphic/AssetsLoader/MeshLoader.h"
#include "Assets/AssetManager.h"
#include "../Include/General/Tool/IO.h"
#include "../Include/General/Tool/String.h"
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
    int index = 1;
    Vector3 vector3{};
    std::vector<float> position;
    std::vector<float> color;
    std::vector<float> normal;
    std::vector<float> tangent;
    std::vector<float> texCoord1;
    IO::ReadFilePerLine(path, [&meshAsset, &result, &face, &group, &temp, &index, &vector3, &position, &color, &normal, &texCoord1](std::string& info) {
        //判断数据类型
        unsigned short int infoType = (unsigned short int)info[0] + (unsigned short int)info[1];
        String::Split(info, ' ', result);
        unsigned int size = result.size();
        switch (infoType) {
            case 150:   //vertex
                for (unsigned int i = 1; i < 4 && i < size ; ++i) {
                    position.push_back(std::stof(result[i]));
                }
                for (unsigned int i = 4; i < size; ++i) {
                    color.push_back(std::stof(result[i]));
                }
                break;
            case 228:   //normal
                for (unsigned int i = 1; i < 4 && i < size ; ++i) {
                    normal.push_back(std::stof(result[i]));
                }
                break;
            case 234:   //texCoord
                for (unsigned int i = 1; i < 5 && i < size ; ++i) {
                    texCoord1.push_back(std::stof(result[i]));
                }
                break;
            case 134:   //face
                if (result.size() == 4) {
                    //三角化网格
                    for (unsigned int i = 1; i < 4 && i < size ; ++i) {
                        String::Split(result[i],'/',face);
                        group = (int)face.size();
                        for (unsigned int j = 0; j < 3 && j < face.size(); ++j) {
                            vector3.info[j] = std::stoi(face[j]);
                        }
                        if (temp.find(vector3) == temp.end()) {
                            temp.insert(std::pair<Vector3, unsigned int >(vector3, index));
                            if (vector3.info[0] > 0) {
                                //坐标属性
                                unsigned int begin = (vector3.info[0] - 1) * 3;
                                meshAsset->position.push_back(position[begin]);
                                meshAsset->position.push_back(position[begin + 1]);
                                meshAsset->position.push_back(position[begin + 2]);
                                if (!color.empty()) {
                                    meshAsset->color.push_back(position[begin]);
                                    meshAsset->color.push_back(position[begin + 1]);
                                    meshAsset->color.push_back(position[begin + 2]);
                                }
                            }
                            if (!texCoord1.empty()) {
                                //纹理属性
                                unsigned int begin = (vector3.info[1] - 1) * 2;
                                meshAsset->texCoord1.push_back(texCoord1[begin]);
                                meshAsset->texCoord1.push_back(texCoord1[begin + 1]);
                            }
                            if (!normal.empty()) {
                                //法线属性
                                int infoIndex = -1;
                                if (vector3.info[2] < 1) {
                                    infoIndex = 1;
                                } else {
                                    infoIndex = 2;
                                }
                                unsigned int begin = (vector3.info[infoIndex] - 1) * 3;
                                meshAsset->normal.push_back(normal[begin]);
                                meshAsset->normal.push_back(normal[begin + 1]);
                                meshAsset->normal.push_back(normal[begin + 2]);
                            }
                            meshAsset->face.push_back(index++);
                        } else {
                            meshAsset->face.push_back(temp[vector3]);
                        }
                    }
                } else {
                    //未进行三角化网格 ignore
                }
                break;
            default:
                return;
        }
    });
    //填充完数据后对数据进行调整优化
    //step1:index减一
    for (unsigned int & i : meshAsset->face) {
        i = i -1;
    }
    //step2:去除重复点
}
