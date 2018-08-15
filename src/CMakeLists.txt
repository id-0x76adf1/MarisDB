project(MarisDB)

set(MarisDBSources
	noncopyable.h
	pagedfile.h
	pagedfile.cpp
	storagemanager.h
	storagemanager.cpp)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_library(MarisDBLib STATIC ${MarisDBSources})
target_include_directories(MarisDBLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
