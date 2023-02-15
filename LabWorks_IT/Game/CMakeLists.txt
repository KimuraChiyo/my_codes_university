cmake_minimum_required(VERSION 3.16)
project(LB9 LANGUAGES CXX)

option(BUILD_SHARED_LIBS OFF)

add_subdirectory(SFML SFML)
add_library(SFML STATIC IMPORTED)

link_directories(build/SFML/lib)
include_directories(SFML/include)

add_executable(LB9 src/main.cpp)
target_link_libraries(LB9 sfml-system sfml-window sfml-graphics sfml-audio sfml-network)