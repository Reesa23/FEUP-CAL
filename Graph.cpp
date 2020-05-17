//
// Created by tisco on 17/05/2020.
//

#include "Graph.h"

// VERTEX

int Vertex::getId() const { return id;}
double Vertex::getDist() const { return dist;}
Vertex* Vertex::getPath() const { return path;}

// EDGE

Edge::Edge(Vertex* d, double w): dest(d), weight(w) {}

double Edge::getWeight() {return weight;}
Vertex* Edge::getDest() {return dest;}
void Edge::updateWeight(double newWeight) {weight=newWeight;}

// GRAPH

int Graph::getNumVertex() const {return vertexSet.size();}
vector<Vertex *> Graph::getVertexSet() const {return vertexSet;}
