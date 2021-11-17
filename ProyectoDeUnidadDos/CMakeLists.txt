cmake_minimum_required(VERSION 3.20)
project(main)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp metGroups.cpp metPH.cpp Groups.h PH.h)