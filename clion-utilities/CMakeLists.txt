cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        PolymorphEngine/design/include
        PolymorphEngine/design/include/engine
        PolymorphEngine/design/include/engine/component
        PolymorphEngine/design/include/engine/entity
        PolymorphEngine/design/include/engine/config
        PolymorphEngine/design/include/engine/scene
        )

file(GLOB_RECURSE DesignSRC PolymorphEngine/design/*.cpp)
file(GLOB_RECURSE DesignICL PolymorphEngine/design/*.hpp)

add_executable(Engine
        ${DesignSRC}
        ${DesignICL}
        PolymorphEngine/design/include/engine/IPolymorphDisplay.hpp PolymorphEngine/design/include/engine/IPolymorphEvent.hpp)
