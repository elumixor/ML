cmake_minimum_required(VERSION 3.15)
project(machine_learning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -Wno-comment -Wunreachable-code -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls  -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option ${CMAKE_CXX_FLAGS}")

include_directories(include)
include_directories(include/math)
include_directories(include/math/tensor)

add_definitions(-DENABLE_LOGGING)
add_definitions(-DENABLE_ASSERTIONS)
add_definitions(-DENABLE_EXCEPTIONS)

add_executable(machine_learning
        src/main.cpp

        include/declarations.h

        include/assertions.h
        include/exceptions.h
        include/conversions.h

        src/array/indices.cpp

        include/output/printable.h src/output/printable.cpp
        include/output/to_string.h src/output/to_string.cpp

        include/math/tensor.h src/math/tensor.cpp
        include/math/matht.h src/math/matht.cpp
        include/math/random.h src/math/random.cpp

        include/nn/network.h src/nn/network.cpp
        include/nn/layer.h src/nn/layer.cpp
        include/nn/function.h src/nn/function.cpp
        include/nn/layers/fc.h src/nn/layers/fc.cpp

        include/arrays/arrays.h src/array/arrays.cpp
        include/arrays/iterators.h
        include/math/tensor_view.h src/math/tensor_view.cpp
        include/math/flat_view.h src/math/flat_view.cpp
        )