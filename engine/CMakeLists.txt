cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 17)

project("Engine")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>)

add_executable(Engine "main.cpp" "engine.h" "engine.cpp" "subject.h" "subject.cpp" "wrapper.h" "wrapper.cpp")

target_include_directories(Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})