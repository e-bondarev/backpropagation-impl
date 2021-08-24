cmake_minimum_required(VERSION 3.16)

project(backpropagation)

file(GLOB_RECURSE src src/*.cpp)

if(NOT BACKPROPAGATION_STATIC OR BUILD_SHARED_LIBS)
	add_compile_definitions(BACKPROPAGATION_SHARED)
	add_library(backpropagation SHARED ${src})
	target_include_directories(backpropagation PUBLIC include)
else()
	add_library(backpropagation STATIC ${src})
	target_include_directories(backpropagation PUBLIC include)
endif()