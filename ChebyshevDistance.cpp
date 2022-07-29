//
// Created by kalo3 on 27-Jul-22.
//

#include "ChebyshevDistance.hpp"
#include "math.h"
using namespace Geometry;

double ChebyshevDistance::distance(Point p1, Point p2) {
    int dimension=p1.dimension;
    double maxDifference=-1;
    for(int i=0;i<dimension;i++){
        double difference=abs(p1.at(i)-p2.at(i));
        if(maxDifference<difference)
            maxDifference=difference;
    }
    return maxDifference;
}