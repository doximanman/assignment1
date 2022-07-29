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

}

int KNearestNeighbors::numOfPoints() {
    int num=0;
    for(const auto& item:_data){
        num+=(int)item.size();
    }
    return num;
}
vector<vector<double>> KNearestNeighbors::distances(Distance &distance) {
    vector<vector<double>> dists(_data.size());
    for (int i = 0; i < _data.size(); i++) {
        dists.at(i)=vector<double>(_data.at(i).size());
        for (int j = 0; j < _data.at(i).size(); j++) {
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
    if(K>numOfPoints()){
        K=numOfPoints();
    }
    vector<int[2]> result(K);
    for(auto item : result){
        item[0]=INT_MAX;
        item[1]=-INT_MAX;
    }
    vector<vector<double>> dists = distances(distance);
    for (int r = 0; r < K; r++) {
        double min = INT_MAX;
        int indices[2] = {-1, -1};
        for (int i = 0; i < dists.size(); i++) {
            for (int j = 0; j < dists.at(i).size(); j++) {
                if (dists.at(i).at(j) < min && (!contains(&result, new int[]{i, j}))) {
                    indices[0] = i;
                    indices[1] = j;
                    min = dists.at(i).at(j);
                }
            }
        }
        result.at(r)[0] = indices[0];
        result.at(r)[1] = indices[1];
    }
    return result;
}

vector<Point> KNearestNeighbors::nearestNeighbors(int K, Distance &distance) {
    vector<Point> neighbors={};
    vector<int[2]> indices = firstK(K, distance);
    for (int i = 0; i < indices.size(); i++) {
        neighbors.push_back(_data.at(indices.at(i)[0]).at(indices.at(i)[1]));
    }
    return neighbors;
}

int KNearestNeighbors::classify(int K, Distance &distance) {
    vector<int[2]> neighborIndices = firstK(K, distance);
    vector<int> counter(_data.size());
    for (int i = 0; i < _data.size(); i++) {
        counter.at(i) = 0;
    }
    for (auto &index: neighborIndices) {
        counter.at(index[0])++;
    }
    int max = -1;
    int maxType=-1;
    for (int i = 0; i < _data.size(); i++) {
        if (max < counter.at(i)) {
            max = counter.at(i);
            maxType=i;
        }
    }
    return maxType;
}

void KNearestNeighbors::printNearestNeighbors(int K, Distance &distance) {
    vector<Point> neighbors= nearestNeighbors(K,distance);
    for(auto item:neighbors){
        std::cout<< item ;
    }
    std::cout << endl;
}