cmake_minimum_required(VERSION 3.16)

project(test)

file(GLOB_RECURSE src src/*.cpp)

add_executable(test ${src})

target_include_directories(test PUBLIC ../backpropagation/include)
target_link_libraries(test backpropagation)