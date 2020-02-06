cmake_minimum_required(VERSION 3.15)
project(machine_learning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -Wno-comment -Wunreachable-code -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls  -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option ${CMAKE_CXX_FLAGS}")

include_directories(include)

add_definitions(-DENABLE_LOGGING)
add_definitions(-DENABLE_ASSERTIONS)
add_definitions(-DENABLE_EXCEPTIONS)

add_executable(machine_learning src/main.cpp include/declarations.h include/math/tensor.h include/assertions.h include/exceptions.h include/output/printable.h src/output/printable.cpp src/math/tensor.cpp src/exceptions.cpp src/output/to_string.cpp include/math/matht.h src/math/matht.cpp include/conversions.h include/iterable.h src/math/random.cpp include/math/random.h src/iterable.cpp include/nn/network.h src/nn/network.cpp include/nn/layer.h include/nn/function.h src/nn/function.cpp src/nn/layer.cpp include/output/to_string.h src/nn/layers/fc.cpp include/nn/layers/fc.h src/math/tensor_indices_iterable.cpp)