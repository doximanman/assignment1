//
// Created by kalo3 on 27-Jul-22.
//

#ifndef ASS1_CHEBISHEVDISTANCE_HPP
#define ASS1_CHEBISHEVDISTANCE_HPP
#include "Distance.hpp"
namespace Geometry {
    class ChebishevDistance : public Distance {
        public:
            double distance(Point p1, Point p2);
    };
}

#endif //ASS1_CHEBISHEVDISTANCE_HPP
