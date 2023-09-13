cmake_minimum_required(VERSION 3.21)
project(Code)

INCLUDE_DIRECTORIES(ThirdParty)

set(CMAKE_CXX_STANDARD 17)

add_executable(Code main.cpp Source/CustomPtr.cpp Include/Framework/CustomPtr.h Source/CustomAsset.cpp Include/Framework/Assets/CustomAsset.h Source/AssetManager.cpp Include/Framework/Assets/AssetManager.h Include/General/Map.h)
