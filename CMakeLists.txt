cmake_minimum_required(VERSION 3.13)  # CMake version check
project(simple_example)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES src/main.cpp src/Distance.cpp src/Distance.hpp src/ChebyshevDistance.cpp src/ChebyshevDistance.hpp src/EuclideanDistance.cpp src/EuclideanDistance.hpp src/ManhattanDistance.cpp src/ManhattanDistance.hpp src/Point.cpp src/Point.hpp src/CSVManagement.cpp src/CSVManagement.hpp src/KNearestNeighbors.cpp src/KNearestNeighbors.hpp)
# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main ${SOURCE_FILES})