set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(MarisDBTest main.cpp)
target_link_libraries(MarisDBTest Catch2::Catch2)
