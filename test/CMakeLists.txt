set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(MarisDBTestSources
	main.cpp
	storagemanagertest.cpp)

add_executable(MarisDBTest ${MarisDBTestSources})
target_include_directories(MarisDBTest PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(MarisDBTest Catch2::Catch2)
target_link_libraries(MarisDBTest MarisDBLib)
