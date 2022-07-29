cmake_minimum_required(VERSION 3.22)
project(assignment1)

set(CMAKE_CXX_STANDARD 11)

add_executable(assignment1 main.cpp Point.cpp Point.hpp Distance.hpp Distance.cpp EuclidianDistance.cpp EuclidianDistance.hpp ChebishevDistance.cpp ChebishevDistance.hpp ManhattanDistance.cpp ManhattanDistance.hpp KNearestNeighbors.cpp KNearestNeighbors.hpp)
