#include <iostream>
#include "Point.hpp"
#include "EuclideanDistance.hpp"
#include "ChebyshevDistance.hpp"
#include "ManhattanDistance.hpp"
#include "KNearestNeighbors.hpp"
#include <string>
using namespace std;
using namespace Geometry;
int main(int argc,char* argv[]) {
    int K=3;
    if(argc>1){
        K=stoi(argv[1]);
    }
    else{
        cout<<"No argument given - assuming K=3"<<endl;
    }
    Point t0p0({3, 3});
    Point t0p1({1, 2});
    Point t0p2({3, 1});
    Point t0p3({10, 10});
    Point t0p4({5, 3});
    Point t1p0({15, 4});
    Point t1p1({6, 7});
    Point t1p2({4, 3});
    Point t1p3({9, 1});
    Point t1p4({1.8, 0.4});
    Point t2p0({2.3, 2.9});
    Point t2p1({5.1, 2.4});
    Point t2p2({1.7, 6.3});
    Point t2p3({8, 7});
    Point t2p4({5, 2.5});
    Point t2p5({6, 9});
    Point t2p6({50, 2});
    Point t2p7({1.3, 2.5});
    Point t2p8({1.1, 3.1});
    vector<Point> type1={t0p0,t0p1,t0p2,t0p3,t0p4};
    vector<Point> type2={t1p0,t1p1,t1p2,t1p3,t1p4};
    vector<Point> type3={t2p0,t2p1,t2p2,t2p3,t2p4,t2p5,t2p6,t2p7,t2p8};
    vector<vector<Point>> data{type1, type2, type3};
    EuclideanDistance euclid{};
    ManhattanDistance manhat{};
    ChebyshevDistance chebish{};
    cout<< "Distances of " << t1p1 << " from " << t2p2 << ":" << endl;
    cout<< "Euclidean: ";
    cout << euclid.distance(t1p1, t1p3) << " | ";
    cout<< "Manhattan: ";
    cout << manhat.distance(t1p1, t1p3) << " | ";
    cout << "Chebyshev: ";
    cout << chebish.distance(t1p1, t1p3) << endl;
    Point modelPoint({3, 3});
    KNearestNeighbors nearestNeighbors(modelPoint, data);
    cout<< "Distances of " << t0p0 << " from " << modelPoint << ", using the data table";
    cout << " inside of the nearestNeighbor object: " << endl;
    cout<< "Euclidean: ";
    cout << nearestNeighbors.distances(euclid).at(0).at(0) << " | ";
    cout<< "Manhattan: ";
    cout << nearestNeighbors.distances(manhat).at(0).at(0) << " | ";
    cout << "Chebyshev: ";
    cout << nearestNeighbors.distances(chebish).at(0).at(0) << endl;
    cout << "Euclidean K nearest neighbors: " ;
    nearestNeighbors.printNearestNeighbors(K,euclid);
    cout << "Manhattan K nearest neighbors: ";
    nearestNeighbors.printNearestNeighbors(K,manhat);
    cout << "Chebyshev K nearest neighbors: ";
    nearestNeighbors.printNearestNeighbors(K,chebish);
    cout << "Euclidean Classification: " << nearestNeighbors.classify(K,euclid) << endl;
    cout << "Manhattan Classification: " << nearestNeighbors.classify(K,manhat) << endl;
    cout << "Chebyshev Classification: " << nearestNeighbors.classify(K,chebish) << endl;

}
