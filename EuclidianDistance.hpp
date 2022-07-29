//
// Created by kalo3 on 27-Jul-22.
//

#ifndef ASS1_EUCLIDIANDISTANCE_HPP
#define ASS1_EUCLIDIANDISTANCE_HPP

#include "Distance.hpp"

namespace Geometry {
    class EuclidianDistance : public Distance {
    public:
        double distance(Point p1, Point p2);
    };
}

#endif //ASS1_EUCLIDIANDISTANCE_HPP
