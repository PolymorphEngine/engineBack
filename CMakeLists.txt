cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        Include
        Include/Engine
        Include/Engine/component
        Include/Engine/entity
        Include/Engine/config
        Include/Engine/scene
        Include/Engine/Utilities
        Include/Engine/Utilities/Types
)

file(GLOB_RECURSE SRC Src/*.cpp)
file(GLOB_RECURSE ICL Include/*.hpp)

add_executable(Engine
        ${SRC}
        ${ICL}
        )
