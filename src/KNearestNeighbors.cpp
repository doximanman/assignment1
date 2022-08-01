//
// Created by kalo3 on 28-Jul-22.
//

#include <cstdlib>
#include <utility>
#include "KNearestNeighbors.hpp"
#include <iostream>

using namespace Geometry;
KNearestNeighbors::KNearestNeighbors(const Point& modelPoint,
                                     vector<vector<Point>> data) : _modelPoint(modelPoint),
                                                                   _data(std::move(data)) {
    int num=0;
    // goes to each data type and counts how many points there are in total.
    for(const auto& item:_data){
        num+=(int)item.size();
    }
    numOfPoints=num;
}
vector<vector<double>> KNearestNeighbors::distances(Distance &distance) {
    // instantiates the distance table.
    vector<vector<double>> dists(_data.size());
    for (int i = 0; i < _data.size(); i++) {
        // instantiates the data list of this type.
        dists.at(i)=vector<double>(_data.at(i).size());
        for (int j = 0; j < _data.at(i).size(); j++) {
            // sets [i][j] of the table to be the distance between the model point and data[i][j].
            dists.at(i).at(j) = distance.distance(_data.at(i).at(j), _modelPoint);
        }
    }
    return dists;
}

bool KNearestNeighbors::contains(vector<int[2]> *list, const int value[2]) {
    for (auto &item: *list) {
        if (item[0] == value[0] && item[1] == value[1]) {
            return true;
        }
    }
    return false;
}

vector<int[2]> KNearestNeighbors::firstK(int K, Distance &distance) {
    if(K>numOfPoints){
        K=numOfPoints;
    }
    vector<int[2]> result(K);
    for(auto item : result){
        item[0]=-1;
        item[1]=-1;
    }
    vector<vector<double>> dists = distances(distance);
    // finds the minimum K times - ignores the last findings (to make sure we get K different elements,
    // and not just the smallest element K times).
    for (int r = 0; r < K; r++) {
        // initialized at infinity so that we're guaranteed to have a number smaller than it.
        double min = LONG_MAX;
        int indices[2] = {-1, -1};
        for (int i = 0; i < dists.size(); i++) {
            for (int j = 0; j < dists.at(i).size(); j++) {
                // if(distance is smaller than the minimum we found && we didn't find this point before as a minimum)
                if (dists.at(i).at(j) < min && (!contains(&result, new int[]{i, j}))) {
                    // save the indices and minimum as the new minimum.
                    indices[0] = i;
                    indices[1] = j;
                    min = dists.at(i).at(j);
                }
            }
        }
        // the indices of the new minimum.
        result.at(r)[0] = indices[0];
        result.at(r)[1] = indices[1];
    }
    return result;
}

vector<Point> KNearestNeighbors::nearestNeighbors(int K, Distance &distance) {
    // simply gets the indices of the nearest neighbors and returns a list of the actual points.
    vector<Point> neighbors={};
    vector<int[2]> indices = firstK(K, distance);
    for (auto & index : indices) {
        neighbors.push_back(_data.at(index[0]).at(index[1]));
    }
    return neighbors;
}

int KNearestNeighbors::classify(int K, Distance &distance) {
    // uses a counter list to count how many points of the closest K points are of each
    // data type, then finds the max of that counter list, and returns the index of it.
    vector<int[2]> neighborIndices = firstK(K, distance);
    // counter list.
    vector<int> counter(_data.size());
    // initializes at 0.
    for (int i = 0; i < _data.size(); i++) {
        counter.at(i) = 0;
    }
    // adds 1 for every occurrence.
    for (auto &index: neighborIndices) {
        counter.at(index[0])++;
    }
    // finds max.
    int max = -1;
    int maxType=-1;
    for (int i = 0; i < _data.size(); i++) {
        if (max < counter.at(i)) {
            max = counter.at(i);
            maxType=i;
        }
    }
    // returns the index of the max.
    return maxType;
}

void KNearestNeighbors::printNearestNeighbors(int K, Distance &distance) {
    vector<Point> neighbors= nearestNeighbors(K,distance);
    // uses the print implementation of Point to print all the points.
    for(const auto& item:neighbors){
        std::cout<< item ;
    }
    std::cout << endl;
}