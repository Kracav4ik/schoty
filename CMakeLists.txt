cmake_minimum_required(VERSION 3.8)
project(schoty)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories(src)

add_subdirectory(src)
