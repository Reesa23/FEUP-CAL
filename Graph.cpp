//
// Created by tisco on 17/05/2020.
//

#include "Graph.h"
using namespace std;

// VERTEX

Vertex::Vertex(int newId, double newX, double newY): id(newId), x(newX), y(newY) {}     // constructor

int Vertex::getId() const { return id;}
double Vertex::getDist() const { return dist;}
Vertex* Vertex::getPath() const { return path;}

// EDGE

Edge::Edge(int newId, Vertex* d, double w): id(newId), dest(d), weight(w) {}      // constructor

double Edge::getWeight() {return weight;}
Vertex* Edge::getDest() {return dest;}
void Edge::updateWeight(double newWeight) {weight=newWeight;}

// GRAPH

Graph::Graph() {}

int Graph::getNumVertex() const {return vertexSet.size();}      // constructor

vector<Edge *> Graph::getEdgeSet() const {return edgeSet;}
vector<Vertex *> Graph::getVertexSet() const {return vertexSet;}

void Graph::addVertex(Vertex * newV) {vertexSet.push_back(newV);}
void Graph::addEdge(Edge *newE) {edgeSet.push_back(newE);}


Vertex* Graph::findVertex(const int id) const {  // CHANGEEEE

    cout<<"id wanted: "<<id;

    for(int i=0;i<vertexSet.size();i++)
    {

        cout<<"\ni: "<<i<<" current id: "<<vertexSet[i]->getId();
        if(vertexSet[i]->getId()==id)
            return vertexSet[i];
    }

    cout << "Vertex non existent";
    return 0x0;                               // CHANGE!!!!! THROW EXCEPTION
}
