cmake_minimum_required(VERSION 3.21)

project(Code)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../CanvasOut/Arc)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../CanvasOut/Lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../CanvasOut/Bin)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(FRAMEWORK_INCLUDE  ${PROJECT_SOURCE_DIR}/Include/Framework)
set(CEREAL_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty/cereal)
set(GLAD_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty/glad/4.6/include)
if (CMAKE_HOST_WIN32)
    set(GLFW_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_Windows/include)
    set(ASSIMP_INCLUDE ${PROJECT_SOURCE_DIR}/ThirdParty/assimp/5.2.5_Windows/include)
elseif (CMAKE_HOST_APPLE)
    set(GLFW_INCLUDE  ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_MacOS/include)
#elseif (CMAKE_HOST_UNIX)
endif()

include_directories(
        ${FRAMEWORK_INCLUDE}
        ${GLFW_INCLUDE}
        ${GLAD_INCLUDE}
        ${CEREAL_INCLUDE}
)

set(FRAMEWORK
        Source/CustomPtr.cpp Include/Framework/CustomPtr.h
        Source/CustomAsset.cpp Include/Framework/Assets/CustomAsset.h
        Source/AssetManager.cpp Include/Framework/Assets/AssetManager.h
        Source/SceneManager.cpp Include/Framework/Scenes/SceneManager.h
        Source/SerializePtr.cpp Include/Framework/SerializePtr.h
        Source/CustomValue.cpp Include/Framework/CustomValue.h
)

set(GENERAL
        Include/General/Container/Map.h
        Source/Debug.cpp
        Include/General/Tool/Debug.h
        Source/Time.cpp
        Include/General/Tool/Time.h
        Include/General/Container/Queue.h
        Source/Cipher.cpp Include/General/Tool/Cipher.h
        Include/General/Container/Deque.h
        Source/IO.cpp Include/General/Tool/IO.h
        Source/String.cpp Include/General/Tool/String.h
        Source/Color.cpp
        Include/General/Math/Color.h
        Include/General/Math/CommonMath.cpp
        Include/General/Math/CommonMath.h)

set(Entity
        Source/CustomEntity.cpp Include/Framework/Scenes/CustomEntity.h
        Source/GameObject.cpp Include/Framework/Scenes/GameObject.h
        Source/Component.cpp Include/Framework/Scenes/Component.h
        Source/Transform.cpp Include/Engine/Transform.h
        Source/Renderer.cpp Include/Core/Graphic/RenderData/Components/Renderer.h
        Source/GraphicCore.cpp Include/Core/Graphic/Core/GraphicCore.h)

set(Asset
        Source/TextureAsset.cpp
        Source/Scene.cpp
        Include/Framework/Scenes/Scene.h Source/GlobalSetting.cpp Include/Framework/GlobalSetting.h Source/ShaderAsset.cpp Include/Core/Graphic/Assets/ShaderAsset.h Source/MeshAsset.cpp Include/Core/Graphic/Assets/MeshAsset.h Source/TextureAsset.cpp Include/Core/Graphic/Assets/TextureAsset.h Source/MaterialAsset.cpp Include/Core/Graphic/Assets/MaterialAsset.h Source/AssetLog.cpp Include/Framework/Assets/AssetLog.h)

set(Core
        Source/Graphic.cpp Include/Core/Graphic/Graphic.h
        Source/OpenGLGraphicCore.cpp Include/Core/Graphic/Core/OpenGL/OpenGLGraphicCore.h
        Source/RenderData.cpp Include/Core/Graphic/RenderData.h
        Source/GraphicPipeline.cpp Include/Core/Graphic/Pipeline/GraphicPipeline.h
        Source/GraphicFeature.cpp Include/Core/Graphic/Pipeline/GraphicFeature.h
        Source/ForwardPipeline.cpp Include/Core/Graphic/Pipeline/Pipeline/ForwardPipeline.h
        Source/OpaqueFeature.cpp Include/Core/Graphic/Pipeline/Pipeline/ForwardFeatures/OpaqueFeature.h
        Source/SkyboxFeature.cpp Include/Core/Graphic/Pipeline/Pipeline/ForwardFeatures/SkyboxFeature.h
        Source/TransparentFeature.cpp Include/Core/Graphic/Pipeline/Pipeline/ForwardFeatures/TransparentFeature.h
        Source/ShaderLoader.cpp Include/Core/Graphic/AssetsLoader/ShaderLoader.h
        Source/MeshLoader.cpp Include/Core/Graphic/AssetsLoader/MeshLoader.h
        Source/CameraManager.cpp Include/Core/Graphic/RenderData/CameraManager.h
        Source/Camera.cpp Include/Core/Graphic/RenderData/Components/Camera.h
        Source/Light.cpp Include/Core/Graphic/RenderData/Components/Light.h
        Source/LightManager.cpp Include/Core/Graphic/RenderData/LightManager.h
        Source/RendererManager.cpp Include/Core/Graphic/RenderData/RendererManager.h
        Source/OpenGLShaderStorage.cpp Include/Core/Graphic/Core/OpenGL/OpenGLShaderStorage.h
        Source/OpenGLMeshStorage.cpp Include/Core/Graphic/Core/OpenGL/OpenGLMeshStorage.h
        Source/OpenGLRenderTextureStorage.cpp
        Include/Core/Graphic/Core/OpenGL/OpenGLRenderTextureStorage.h
        Source/OpenGLTextureStorage.cpp
        Include/Core/Graphic/Core/OpenGL/OpenGLTextureStorage.h
        Source/RenderTextureDescribe.cpp
        Include/Core/Graphic/Core/RenderTexture.h
)

if (CMAKE_HOST_WIN32)
    add_executable(Code main.cpp glad.c ${Core} ${Entity} ${Asset} ${FRAMEWORK} ${GENERAL} Source/Engine.cpp Include/Engine.h)
    set(GLFW_LIB ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_Windows/lib-mingw-w64/libglfw3.a) #编译动态库就报错
elseif (CMAKE_HOST_APPLE)
    add_executable(Code main.cpp glad.c ${FRAMEWORK} ${Entity} ${Asset} ${Core} ${GENERAL} Source/Engine.cpp Include/Engine.h)
    set(GLFW_LIB ${PROJECT_SOURCE_DIR}/ThirdParty/glfw/3.3.8_MacOS/lib/libglfw.dylib)
#elseif (CMAKE_HOST_UNIX)
endif()

target_link_libraries(Code ${GLFW_LIB})
