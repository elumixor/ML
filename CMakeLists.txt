cmake_minimum_required(VERSION 3.15)
project(calculus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -pedantic -Wno-comment -Wunreachable-code -Winit-self -Wlogical-op -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option ${CMAKE_CXX_FLAGS}")

include_directories(include)

add_definitions(-DENABLE_LOGGING)
add_definitions(-DENABLE_ASSERTIONS)
add_definitions(-DENABLE_EXCEPTIONS)

add_executable(calculus src/main.cpp include/def.h include/tensor.h include/assertions.h include/exceptions.h include/output.h src/output.cpp src/tensor.cpp src/exceptions.cpp src/string_def.cpp include/functional.h src/functional.cpp include/conversions.h include/iterable.h)