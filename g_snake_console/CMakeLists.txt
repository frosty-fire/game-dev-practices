cmake_minimum_required(VERSION 3.28)
project(g_snake)

# set(CMAKE_CXX_STANDARD 26)

add_executable(main src/main.cpp
        src/Game.cpp
        src/Snake.cpp
        src/Board.cpp
        src/Apple.cpp
        src/Controller.cpp
        src/Board.cpp)

target_include_directories(main PRIVATE include)

