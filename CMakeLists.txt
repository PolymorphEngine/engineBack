cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        include
        include/Engine
        include/Engine/component
        include/Engine/entity
        include/Engine/config
        include/Engine/scene
        include/Engine/Utilities
        include/Engine/Utilities/Types
)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE ICL include/*.hpp)

add_executable(Engine
        ${SRC}
        ${ICL}
        )
