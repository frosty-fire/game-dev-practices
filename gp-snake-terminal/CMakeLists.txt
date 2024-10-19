cmake_minimum_required(VERSION 3.28)

project(g-snake-terminal
        VERSION 0.1.0
        DESCRIPTION "Snake Terminal Game")

set(CMAKE_CXX_STANDARD 26)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)