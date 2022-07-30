cmake_minimum_required(VERSION 3.13)  # CMake version check
project(assignment1)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp Point.hpp Point.cpp Distance.hpp Distance.cpp ManhattanDistance.hpp ManhattanDistance.cpp EuclideanDistance.hpp EuclideanDistance.cpp ChebyshevDistance.hpp ChebyshevDistance.cpp KNearestNeighbors.hpp KNearestNeighbors.cpp)

add_executable(main ${SOURCE_FILES})