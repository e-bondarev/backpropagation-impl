cmake_minimum_required(VERSION 3.16)

project(backpropagation-impl)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(BACKPROPAGATION_STATIC TRUE)

add_subdirectory(backpropagation)
add_subdirectory(test)