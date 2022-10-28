cmake_minimum_required(VERSION 3.19)
project(Engine)

set(CMAKE_CXX_STANDARD 20)



add_subdirectory(lib/myxmlpp)
set_target_properties(myxmlpp PROPERTIES POSITION_INDEPENDENT_CODE ON)

file(GLOB_RECURSE SRC src/*.cpp)
file(GLOB_RECURSE ICL include/*.hpp)
file(GLOB_RECURSE ICL_HEADERS include/polymorph/*.hpp)

add_library(polymorphEngine
        ${SRC}
        ${ICL}
        ${ICL_HEADERS}
)
target_include_directories(polymorphEngine PUBLIC
        lib/myxmlpp/include
        include
)

target_link_libraries(polymorphEngine myxmlpp)
if (UNIX)
    target_link_libraries(polymorphEngine dl)
    target_link_options(polymorphEngine PUBLIC "-Wl,--no-undefined")
endif()
set_target_properties(polymorphEngine PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(TestMain EXCLUDE_FROM_ALL
        SampleProject/test_main.cpp
)

target_link_libraries(TestMain polymorphEngine)