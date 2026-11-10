cmake_minimum_required(VERSION 3.10)
project(music)
include_directories(inc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall)

option(SHOW_ERRORS "" OFF)
if(SHOW_ERRORS)
    add_definitions(-DSHOW_ERRORS)
endif()

add_executable(${PROJECT_NAME}
    inc/music/music.hpp
    src/main.cpp
    src/music.cpp
)
