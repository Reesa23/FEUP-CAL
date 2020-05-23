#ifndef FICHAJUNG_ALGORITHMS_H
#define FICHAJUNG_ALGORITHMS_H


#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include "Graph.h"
#include "MutablePriorityQueue.h"

using namespace std;


void dijkstra(Graph &mainGraph, int initial_id);

void createWeightMatrix(Graph g, vector<vector<double>> &matrix);
void bruteForce(Graph mainGraph, int startId, vector<vector<double>> &weightsMatrix, vector<int> &bestPathNodes);



#endif //FICHAJUNG_ALGORITHMS_H
