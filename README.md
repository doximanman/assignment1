# K Nearest Neighbors

This project is coded in C++.
## The Problem
We have a set of points (data), and each point belongs to some group (**Classified**).
Given a new point that is not classified, we need to decide which group that point should belong to.
There are different ways to do this, but one way is to use the **K Nearest Neighbors** algorithm.
## What is the K Nearest Neighbors Algorithm?
Given a group of classified points - our **data**, a number K - our **'accuracy'**, and a new point -  we need to classify that point.
This algorithm solves this problem by finding the K closest<sup>(1)</sup> points in the data from the point, and it decides the classification
of the point by the type that has the most points out of those K points.

<sup>(1)</sup> Closest is relative to a given distance function. In this algorithm we generalized it so that any distance function would work - and in our example we used 3 distances: Euclidian, Manhattan, and Chebyshev.

## Example
We have a set of points, lets say (1,1) (2,2) (3,3) (4,4) and (3.5,3.5), and they are classified:

group A: (1,1) , (2,2) , (3,3)

group B: (4,4) , (3.5,3.5)

And we are given the unclassified point (2.5,2.5), and 'accuracy' - K=3, and we need to classify the point.

Using Manhattan distance, the 3 closest points are : (2,2),(3,3),(3.5,3.5). 2 of those points belong to group A,
and 1 belongs to group B, so we conclude that the point should belong to group A.

## How we implemented it
**generic point class**:
- Can be of any dimension, with a given coordinates list.
- Can return any of its coordinates at will using the **at** function.

**abstract distance class**:
- Has an abstract distance function (not implemented).
- Whenever a distance function is needed in the code, an abstract refrence to the Distance class is used, to uphold generality.

**KNearestNeighbors class**:
- Constructed with a data table and a model point.
- Has 3 main functions:
- **distances(instance of Distance)**: returns a table of all the distances of the data points from the model point, given a distance function.
  **logic**: Simply creates a new table, iterates over the data table and inserts the distances of each point to the model point.
- **NearestNeighbors(integer K, instance of Distance)**: returns a list of the K nearest neighbors
  **logic**: Finds the closest point to the model point using the distances array k times, and ignores the previous minimums it found.
- **classify(integer K, instance of Distance)**: returns the classification of the point using the K nearest neighbors.
  **logic**: Simply uses the K nearest neighbors list and finds which type appears the most.

We also created extenders of the Distance class, specifically Euclidian distance, Manhattan distance, and Chebyshev distance.

## How to Use
For now, insert some K into the command line arguments when running main.cpp, and you'll get 
an output of some testing code (explaination in the output of the code).
And there are comments throughout the code, wherever explanation may be needed.
