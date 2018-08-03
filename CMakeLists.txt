cmake_minimum_required(VERSION 3.11)
project(MarisDB)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
file(GLOB STORAGE_SOURCES src/storage/*.cpp)

add_executable(MarisDB ${STORAGE_SOURCES} src/main.cpp)
