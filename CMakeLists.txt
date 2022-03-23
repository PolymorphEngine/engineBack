cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        include
        lib/myxmlpp/include
        include/Engine
        include/Exceptions
        include/Engine/component
        include/Engine/component/default
        include/Engine/component/default/drawables
        include/Engine/component/default/colliders
        include/Engine/entity
        include/Engine/config
        include/Engine/scene
        include/Engine/settings
        include/Engine/Utilities
        include/Engine/Utilities/Types
)

add_subdirectory(lib/myxmlpp)
set_target_properties(myxmlpp PROPERTIES POSITION_INDEPENDENT_CODE ON)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE ICL include/*.hpp)

add_library(PolymorphEngine
        ${SRC}
        ${ICL}
)
target_link_libraries(PolymorphEngine myxmlpp dl)
target_link_options(PolymorphEngine PUBLIC "-Wl,--no-undefined")
set_target_properties(PolymorphEngine PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(TestMain EXCLUDE_FROM_ALL
        SampleProject/test_main.cpp
)

target_link_libraries(TestMain PolymorphEngine)