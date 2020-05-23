#include "Algorithms.h"

using namespace std;


// DIJKSTRA

/***************Algorithms.cpp***************/

void dijkstra(Graph &mainGraph, int initial_id) {


    MutablePriorityQueue<Vertex> pq;

    for (auto vertex : mainGraph.getVertexSet()) {
        vertex->setDist(999999);
        vertex->setPath(nullptr);
        if (vertex->getId()==initial_id)
        {
            vertex->setDist(0);
            pq.insert(vertex);
            vertex->setVisited(true);
        }
    }


    while (!pq.empty()) {
        Vertex* v = pq.extractMin();

        for (Edge *e: v->getAdj()) {

            Vertex *a = e->getDest();

            if (a->getDist() > v->getDist() + e->getWeight() || !a->getVisited()) {

                a->setDist(v->getDist() + e->getWeight());
                a->setPath(v);
                a->setVisited(true);

                pq.insert(a);
            }
        }
    }
}

// CREATE WEIGHT MATRIX

void createWeightMatrix(Graph g, vector<vector<double>> &matrix)  // is working
{

    for(int i=0; i< g.getVertexSet().size();i++)
    {
        dijkstra(g, i);
        for(Vertex *v: g.getVertexSet())
        {
            matrix[i].push_back(v->getDist());
        }

    }
}

// TSP - BRUTE FORCE - FIX!!! INFINITE WHILE LOOP

void bruteForce(Graph mainGraph, int startId, vector<vector<double>> &weightsMatrix, vector<int> &bestPathNodes) //first and last vertex id
{

    cout<<"\nbruteforce";
    vector<int> vertexIds;  // all vertices' id's except for the starting one's
    for(int i= 0; i<mainGraph.getVertexSet().size();i++)
    {
        if(i!=startId)
            vertexIds.push_back(i);
    }
    cout<<"\nsize: "<<vertexIds.size();

   // vector<int> bestPathNodes;
    vector<int> currentPathNodes;
    int currentPathWeight=0;

    int minPath = INT_MAX;
    do{
        cout<<endl<<"while";
        currentPathNodes.clear();
        currentPathWeight=0;

        int k=startId;
        for(int i=0; i<vertexIds.size();i++)
        {
            currentPathWeight += weightsMatrix[k][vertexIds[i]];
            k = vertexIds[i];
            currentPathNodes.push_back(i);
        }
        currentPathWeight += weightsMatrix[k][startId];

        //update minimum
        if(currentPathWeight < minPath)
        {
            minPath = currentPathWeight;
            bestPathNodes = currentPathNodes;
        }
    } while (next_permutation(vertexIds.begin(),vertexIds.end()));


 //   return bestPathNodes;

}