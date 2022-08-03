//
// Created by kalo3 on 27-Jul-22.
//

#include "Distance.hpp"

using namespace Geometry;

double Distance::absoluteValue(double x){
    if(x<0){
        return -x;
    }
    return x;
}
