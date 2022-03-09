cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        ../include
        ../include/engine
        ../include/engine/component
        ../include/engine/entity
        ../include/engine/config
        ../include/engine/scene
        ../include/engine/Utilities
        ../include/engine/Utilities/Types
)

file(GLOB_RECURSE DesignSRC ../design/*.cpp)
file(GLOB_RECURSE DesignICL ../include/*.hpp)

add_executable(EngineDesign
        ${DesignSRC}
        ${DesignICL}
        )
