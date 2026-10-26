cmake_minimum_required(VERSION 3.10)
project(playlist)
include_directories(inc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(SHALLOW_COPY "" OFF)
if(SHALLOW_COPY)
    add_definitions(-DSHALLOW_COPY)
endif()

add_executable(${PROJECT_NAME}
    inc/playlist/playlist.hpp
    src/main.cpp
    src/playlist.cpp
)
