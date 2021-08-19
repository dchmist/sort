project(sortowanie)
cmake_minimum_required(VERSION 3.4)
add_definitions( "-Wall -g3 -std=c++17" )

set(HOME_LOC ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${HOME_LOC})

add_executable(Sort
	main.cpp
	ParseArgs.cpp
	Sort/SortManager.cpp
	Sort/SortTypes/BubbleSort.cpp
	Sort/SortTypes/QuickSort.cpp
	FileSupport/FileHandler.cpp
	Factory/SortFactory.cpp
)