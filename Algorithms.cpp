#include "Algorithms.h"

using namespace std;

// DIJKSTRA

// TSP - BRUTE FORCE

vector<int> bruteForce(Graph mainGraph, int startId) //first and last vertex id
{

    //weightMatrix
    vector<vector<int>> weightMatrix = {{0,10,15,20},{10,0,35,25}};  // TEMPORARY VALUES

    vector<int> vertexIds;  // all vertices' id's except for the starting one's
    for(int i= 0; i<mainGraph.getVertexSet().size();i++)
    {
        if(i!=startId)
            vertexIds.push_back(i);
    }

    // !!!! IT NEEDS DIJKSTRA TO WORK CAUSE IT NEEDS TO BE A COMPLETE MATRIX

    vector<int> bestPathNodes;
    vector<int> currentPathNodes;
    int currentPathWeight=0;

    int minPath = INT_MAX;
    do{
        currentPathNodes.clear();
        currentPathWeight=0;

        int k=startId;
        for(int i=0; i<vertexIds.size();i++)
        {
            currentPathWeight += weightMatrix[k][vertexIds[i]];
            k = vertexIds[i];
            currentPathNodes.push_back(i);
        }
        currentPathWeight += weightMatrix[k][startId];

        //update minimum
        if(currentPathWeight < minPath)
        {
            minPath = currentPathWeight;
            bestPathNodes = currentPathNodes;
        }
    } while (next_permutation(vertexIds.begin(),vertexIds.end()));

    return bestPathNodes;

}