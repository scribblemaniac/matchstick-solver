# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(matchstick-solver)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add header files
set(HEADERS
    include/Numeric\ Character.hpp
)

# Add source files
set(SOURCES
    src/main.cpp
    src/Numeric\ Character.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})
