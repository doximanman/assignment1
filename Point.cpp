//
// Created by kalo3 on 27-Jul-22.
//

#include "Point.hpp"

using namespace Geometry;
Point::Point(vector<double> coordinates):dim((int)coordinates.size()),_coordinates((int)coordinates.size()) {
    // copies the given vector as coordinates.
    for(int i=0;i<dim;i++){
        _coordinates.at(i)=coordinates.at(i);
    }
}
Point::Point(const Point &other):dim(other.dim),_coordinates(other.dim) {
    // copies the other point's coordinates as the point's coordinates.
    for(int i=0;i<dim;i++){
        _coordinates.at(i)=other._coordinates.at(i);
    }
}

int Point::dimension() const {
    return dim;
}
double Point::at(int position) const{
    return _coordinates.at(position);
}

ostream& operator<<(ostream &os, const Geometry::Point &a){
    os<<"(";
    for(int i=0;i<a.dimension()-1;i++){
        os<<a.at(i)<<",";
    }
    return os<<a.at(a.dimension()-1)<<") ";
}