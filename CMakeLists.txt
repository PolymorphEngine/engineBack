cmake_minimum_required(VERSION 3.17)
project(myxmlpp)

set(CMAKE_CXX_STANDARD 20)
set(LIBRARY_OUTPUT_PATH  ../)
set(EXECUTABLE_OUTPUT_PATH  ../)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE UNIT_TESTS_SRCS tests/unit-testing/*.cpp)
file(GLOB_RECURSE INCS myxmlpp/*.hpp)

include_directories(include)
include_directories(include/exceptions)

add_library(myxmlpp ${SRCS} ${INCS})

add_executable(myxmlppexec tests/test.cpp)
target_link_directories(myxmlppexec PUBLIC myxmlpp)
target_link_libraries(myxmlppexec myxmlpp)

add_executable(unit-tests ${UNIT_TESTS_SRCS})
target_link_libraries(unit-tests criterion)
target_link_directories(unit-tests PUBLIC myxmlpp)
target_link_libraries(unit-tests myxmlpp)
