cmake_minimum_required(VERSION 3.26)
project(mindmaster)

set(CMAKE_CXX_STANDARD 17)

add_executable(mindmaster main.cpp
        cmake-build-debug/mindmaster.cpp
        cmake-build-debug/mindmaster.h
        mind.cpp
        mind.h)
