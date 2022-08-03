cmake_minimum_required(VERSION 3.13)  # CMake version check
project(assignment1)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES src/main.cpp src/Point.hpp src/Point.cpp src/Distance.hpp src/Distance.cpp src/ManhattanDistance.hpp src/ManhattanDistance.cpp src/EuclideanDistance.cpp src/ChebyshevDistance.hpp src/ChebyshevDistance.cpp src/KNearestNeighbors.hpp src/KNearestNeighbors.cpp src/CSVManagement.hpp src/CSVManagement.cpp)

add_executable(main ${SOURCE_FILES})
