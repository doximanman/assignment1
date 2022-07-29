//
// Created by kalo3 on 27-Jul-22.
//

#include "EuclidianDistance.hpp"
#include "Distance.hpp"
#include "math.h"

using namespace Geometry;

double EuclidianDistance::distance(Point p1, Point p2) {
    int dimension = p1.dimension();
    double sumOfSquares = 0;
    for (int i = 0; i < dimension; i++) {
        double difference = abs(p1.at(i) - p2.at(i));
        sumOfSquares += difference * difference;
    }
    return sqrt(sumOfSquares);
}