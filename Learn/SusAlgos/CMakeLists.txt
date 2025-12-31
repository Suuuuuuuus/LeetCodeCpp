cmake_minimum_required(VERSION 3.20)
project(SusAlgos LANGUAGES CXX)

# Source files
file(GLOB SRC_FILES "src/*.cpp")

# Static library
add_library(SusAlgos STATIC ${SRC_FILES})

# Public include path for consumers
target_include_directories(SusAlgos PUBLIC include)
