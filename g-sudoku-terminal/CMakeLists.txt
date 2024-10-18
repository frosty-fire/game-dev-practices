cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 26)

project(g-sudoku-terminal
        VERSION 0.1.0
        DESCRIPTION "Sudoku Terminal")

file(GLOB SOURCES src/*.cpp)

set(CURSES_NEED_NCURSES TRUE)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE include)