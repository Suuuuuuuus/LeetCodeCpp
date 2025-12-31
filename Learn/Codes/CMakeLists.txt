cmake_minimum_required(VERSION 3.20)
project(Codes LANGUAGES CXX)

# Build executable
add_executable(Codes src/main.cpp)

# Link library
target_link_libraries(Codes PRIVATE SusAlgos)
