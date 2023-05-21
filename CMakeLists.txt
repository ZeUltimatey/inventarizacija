cmake_minimum_required(VERSION 3.23)
project(inventarizacija)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(inventarizacija ${SOURCE_FILES})
