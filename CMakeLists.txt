cmake_minimum_required(VERSION 3.11)
project(MarisDB)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party/Catch2)
add_subdirectory(src)
add_subdirectory(test)
