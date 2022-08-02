//
// Created by kalo3 on 28-Jul-22.
//

#ifndef ASS1_KNEARESTNEIGHBORS_HPP
#define ASS1_KNEARESTNEIGHBORS_HPP

#include "Distance.hpp"
class KNearestNeighbors {
private:
    /**
     * vector of Point vectors where the first dimension is the data
     * type, and the second dimension is the data of that type.
     */
    vector<vector<Geometry::Point>> _data;
    Geometry::Point _modelPoint;
    /**
     * returns the indices of the K closest points to the model point.
     * @return
     */
    vector<int[2]> firstK(int K, Geometry::Distance &distance);
    /**
     * @param list
     * @param value
     * @return whether value is in list.
     */
    static bool contains(vector<int[2]> *list, const int value[2]);
    /**
     * total number of points in the data table.
     */
    int numOfPoints;

public:
    /**
     * Constructs the data table and the model point according to the given values.
     * @param modelPoint
     * @param data
     */
    KNearestNeighbors(const Geometry::Point& modelPoint, vector<vector<Geometry::Point>> data);
    /**
     * @param distance Distance function
     * @return a table of all the distances from the point (according to the data table -
     *         in the same order)
     */
    vector<vector<double>> distances(Geometry::Distance &distance);
    /**
     * @param K
     * @param distance
     * @return K nearest neighbors, in accordance with the provided distance function.
     */
    vector<Geometry::Point> nearestNeighbors(int K, Geometry::Distance &distance);

    // returns the index of the determined data type.
    /**
     * Classifies the point according to the closest K points - the
     * type that has the most points from the K points will be the classification.
     * @param K
     * @param distance
     * @return the classification.
     */
    int classify(int K,Geometry::Distance &distance);
    /**
     * Prints the K nearest members, according to the distance function.
     * @param K
     * @param distance
     */
    void printNearestNeighbors(int K,Geometry::Distance &distance);
};

#endif //ASS1_KNEARESTNEIGHBORS_HPP
