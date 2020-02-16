cmake_minimum_required(VERSION 3.15)
project(machine_learning)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -Wno-comment -Wunreachable-code -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls  -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option ${CMAKE_CXX_FLAGS}")

include_directories(include)

add_definitions(-DENABLE_LOGGING)
add_definitions(-DENABLE_ASSERTIONS)
add_definitions(-DENABLE_EXCEPTIONS)

add_executable(machine_learning
        src/main.cpp

        include/common/declarations.h

        include/common/assertions.h
        include/common/exceptions.h
        include/common/conversions.h

        include/collections/arrays.h src/collections/arrays.cpp
        include/collections/composite_index.h src/collections/composite_index.cpp
        include/collections/tensor.h src/collections/tensor.cpp

        include/output/printable.h src/output/printable.cpp
        include/output/to_string.h src/output/to_string.cpp

        include/random.h src/random.cpp

        include/nn/network.h src/nn/network.cpp
        include/nn/layer.h src/nn/layer.cpp
        include/nn/function.h src/nn/function.cpp
        include/nn/layers/fc.h src/nn/layers/fc.cpp

        include/collections/pair.h)