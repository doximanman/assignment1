//
// Created by kalo3 on 28-Jul-22.
//

#ifndef ASS1_KNEARESTNEIGHBORS_HPP
#define ASS1_KNEARESTNEIGHBORS_HPP

#include "Distance.hpp"
using namespace Geometry;

class KNearestNeighbors {
private:
    // vector of Point vectors where the first dimension is the data
    // type, and the second dimension is the data of that type.
    vector<vector<Point>> _data;
    Point _modelPoint;

    vector<int[2]> firstK(int K, Distance &distance);

    static bool contains(vector<int[2]> *list, const int value[2]);
    int numOfPoints();

public:
    KNearestNeighbors(const Point& modelPoint, vector<vector<Point>> data);

    vector<vector<double>> distances(Distance &distance);

    vector<Point> nearestNeighbors(int K, Distance &distance);

    // returns the index of the determined data type.
    int classify(int K,Distance &distance);
    void printNearestNeighbors(int K,Distance &distance);
};

#endif //ASS1_KNEARESTNEIGHBORS_HPP
