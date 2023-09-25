cmake_minimum_required(VERSION 3.21)

project(Code)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../CanvasOut/Arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../CanvasOut/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../CanvasOut/Bin)

set(FRAMEWORK_INCLUDE  ${PROJECT_SOURCE_DIR}/Include/Framework)
set(CEREAL_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty/cereal)
set(GLAD_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty/glad/4.6/include)
if (CMAKE_HOST_WIN32)
    set(GLFW_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_Windows/include)
elseif (CMAKE_HOST_APPLE)
    set(GLFW_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_MacOS/include)
elseif (CMAKE_HOST_UNIX)

endif()

include_directories(
        ${FRAMEWORK_INCLUDE}
        ${GLFW_INCLUDE}
        ${GLAD_INCLUDE}
        ${CEREAL_INCLUDE}
)

#link_directories(
#        ${GLFW_INCLUDE}
#)

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
        Source/CustomEntity.cpp Include/Framework/Scenes/CustomEntity.h
        Source/GameObject.cpp Include/Framework/Scenes/GameObject.h
        Source/Component.cpp Include/Framework/Scenes/Component.h
        Source/Transform.cpp Include/Engine/Transform.h
        Source/Renderer.cpp Include/Core/Graphic/Renderer.h
        Source/GraphicCore.cpp Include/Core/Graphic/Core/GraphicCore.h)

set(Asset
        Source/TextureAsset.cpp
        Include/Core/Graphic/TextureAsset.h
        Source/Scene.cpp
        Include/Framework/Scenes/Scene.h Source/GlobalSetting.cpp Include/Framework/GlobalSetting.h Source/ShaderAsset.cpp Include/Core/Graphic/Assets/ShaderAsset.h Source/MeshAsset.cpp Include/Core/Graphic/Assets/MeshAsset.h Source/TextureAsset.cpp Include/Core/Graphic/Assets/TextureAsset.h Source/MaterialAsset.cpp Include/Core/Graphic/Assets/MaterialAsset.h)

set(Core
        Source/Graphic.cpp Include/Core/Graphic/Graphic.h
        Source/GraphicOpenGLCore.cpp Include/Core/Graphic/Core/GraphicOpenGLCore.h
        Source/RenderData.cpp Include/Core/Graphic/RenderData.h
        Source/GraphicPipeline.cpp Include/Core/Graphic/Pipeline/GraphicPipeline.h)

if (CMAKE_HOST_WIN32)
    add_executable(Code main.cpp glad.c ${Core} ${Entity} ${Asset} ${FRAMEWORK} ${GENERAL} Source/Engine.cpp Include/Engine.h)
    set(GLFW_LIB ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_Windows/lib-mingw-w64/libglfw3.a) #编译动态库就报错
elseif (CMAKE_HOST_APPLE)
    add_executable(Code main.cpp glad.c ${FRAMEWORK} ${Entity} ${Asset} ${Core} ${GENERAL} Source/Engine.cpp Include/Engine.h)
    set(GLFW_LIB ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_MacOS/lib/libglfw.dylib)
elseif (CMAKE_HOST_UNIX)

endif()

target_link_libraries(Code ${GLFW_LIB})
