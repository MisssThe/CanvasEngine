cmake_minimum_required(VERSION 3.21)

project(Code)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../CanvasOut/Arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../CanvasOut/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../CanvasOut/Bin)

set(FRAMEWORK_INCLUDE  ${PROJECT_SOURCE_DIR}/Include/Framework)
set(THIRD_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty)

include_directories(${FRAMEWORK_INCLUDE} ${THIRD_INCLUDE})

set(FRAMEWORK
        Source/CustomPtr.cpp Include/Framework/CustomPtr.h
        Source/CustomAsset.cpp Include/Framework/Assets/CustomAsset.h
        Source/AssetManager.cpp Include/Framework/Assets/AssetManager.h
        Source/SceneManager.cpp Include/Framework/Scenes/SceneManager.h Source/SerializePtr.cpp Include/Framework/SerializePtr.h)

set(GENERAL
        Include/General/Map.h
        Source/Debug.cpp
        Include/General/Debug.h
        Source/Time.cpp
        Include/General/Time.h Include/General/Queue.h Source/Cipher.cpp Include/General/Cipher.h Include/General/Deque.h)

set(Entity
        Source/CustomEntity.cpp Include/Framework/Scenes/CustomEntity.h Source/GameObject.cpp Include/Framework/Scenes/GameObject.h Source/Component.cpp Include/Framework/Scenes/Component.h Source/Transform.cpp Include/Engine/Transform.h Source/Renderer.cpp Include/Engine/Renderer.h)

set(Asset
        Include/Engine/Graphic/TextureAsset.cpp
        Include/Engine/Graphic/TextureAsset.h
        Source/Scene.cpp
        Include/Framework/Scenes/Scene.h)

if (CMAKE_HOST_WIN32)
    add_executable(Code main.cpp  ${Entity} ${Asset} ${FRAMEWORK} ${GENERAL} Source/Engine.cpp Include/Engine.h)
elseif (CMAKE_HOST_APPLE)
    add_executable(Code main.cpp ${FRAMEWORK} ${Entity} ${Asset} ${GENERAL} Source/Engine.cpp Include/Engine.h)
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif()