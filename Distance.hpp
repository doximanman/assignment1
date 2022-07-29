//
// Created by kalo3 on 27-Jul-22.
//

#ifndef ASS1_DISTANCE_HPP
#define ASS1_DISTANCE_HPP

#include "Point.hpp"

namespace Geometry {
    class Distance {
    public:
        virtual double distance(Point p1,Point p2)=0;
    };
}
#endif //ASS1_DISTANCE_HPP
