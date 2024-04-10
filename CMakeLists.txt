# CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(matchstick-solver)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add header files
set(HEADERS
    src/Character.hpp
    src/NumericCharacter.hpp
    src/OperatorCharacter.hpp
    src/EqualityCharacter.hpp
    src/Equation.hpp
    src/ExpNodes.hpp
    src/Operator.hpp
    src/ConsoleOutput.hpp
)

# Add source files
set(SOURCES
    src/main.cpp
    src/Character.cpp
    src/NumericCharacter.cpp
    src/OperatorCharacter.cpp
    src/Equation.cpp
    src/ExpNodes.cpp
    src/ConsoleOutput.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})
