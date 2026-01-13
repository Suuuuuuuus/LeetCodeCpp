cmake_minimum_required(VERSION 3.20)
project(MyProjects LANGUAGES CXX)

set(CMAKE_OSX_ARCHITECTURES x86_64)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(SusAlgos)
add_subdirectory(Codes)
add_subdirectory(tests)
