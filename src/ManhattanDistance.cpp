//
// Created by kalo3 on 27-Jul-22.
//

#include "ManhattanDistance.hpp"

using namespace Geometry;

double ManhattanDistance::distance(Point p1, Point p2) {
    int dimension=p1.dimension;
    double sum=0;
    for(int i=0;i<dimension;i++){
        sum+=std::abs(p1.at(i)-p2.at(i));
    }
    return sum;
}