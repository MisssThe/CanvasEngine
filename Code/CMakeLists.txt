cmake_minimum_required(VERSION 3.21)

project(Code)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")


set(FRAMEWORK_INCLUDE  ${PROJECT_SOURCE_DIR}/Include/Framework)
set(THIRD_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty)

include_directories(${FRAMEWORK_INCLUDE} ${THIRD_INCLUDE})

set(FRAMEWORK
        Source/CustomPtr.cpp Include/Framework/CustomPtr.h
        Source/CustomAsset.cpp Include/Framework/Assets/CustomAsset.h
        Source/AssetManager.cpp Include/Framework/Assets/AssetManager.h)

set(GENERAL
        Include/General/Map.h)

set(Entity)

set(Asset
        Include/Engine/Graphic/TextureAsset.cpp
        Include/Engine/Graphic/TextureAsset.h)

add_executable(Code main.cpp  ${Entity} ${Asset} ${FRAMEWORK} ${GENERAL})
