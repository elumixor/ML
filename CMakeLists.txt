cmake_minimum_required(VERSION 3.15)
project(calculus)

set(CMAKE_CXX_STANDARD 17)
add_definitions(-DENABLE_LOGGING)

add_executable(calculus src/main.cpp include/def.h include/tensor.h include/assertions.h include/exceptions.h include/printable.h src/printable.cpp src/tensor.cpp src/exceptions.cpp)