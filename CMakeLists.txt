cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        include
        lib/myxmlpp/include
        include/Engine
        include/Engine/component
        include/Engine/entity
        include/Engine/config
        include/Engine/scene
        include/Engine/settings
        include/Engine/Utilities
        include/Engine/Utilities/Types
)

add_subdirectory(lib/myxmlpp)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE ICL include/*.hpp)

add_library(PolymorphEngine
        ${SRC}
        ${ICL}
        )

add_executable(TestMain
        ${SRC}
        ${ICL}
        SampleProject/test_main.cpp
        )

target_link_libraries(TestMain myxmlpp)