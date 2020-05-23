#include "Graph.h"

using namespace std;

// VERTEX

Vertex::Vertex(int newId, double newX, double newY): id(newId), x(newX), y(newY) {}     // constructor

Vertex::~Vertex() {cout<<"destructor called";}  // FAZER DESTRUCTOR

int Vertex::getId() const { return id;}
double Vertex::getDist() const { return dist;}
Vertex* Vertex::getPath() const { return path;}
vector<Edge*> Vertex::getAdj() const {return adj;}

bool Vertex::getVisited() const {return visited;}
void Vertex::setVisited(bool v) {visited=v;}


bool Vertex::operator< (Vertex& a) const{
    if(getDist()<a.getDist())
        return true;
    return false;
}

void Vertex::setDist(double distance) {dist=distance;}
void Vertex::setPath(Vertex *newPath) {path=newPath;}

void Vertex::addAdj(Edge *edge) {
    adj.push_back(edge);
}



// EDGE

Edge::Edge(int newId, Vertex* d, double w): id(newId), dest(d), weight(w) {}      // constructor

double Edge::getWeight() {return weight;}
Vertex* Edge::getDest() {return dest;}
void Edge::updateWeight(double newWeight) {weight=newWeight;}
int Edge::getId() {return id;}




// GRAPH

Graph::Graph() {}

int Graph::getNumVertex() const {return vertexSet.size();}      // constructor

vector<Edge *> Graph::getEdgeSet() const {return edgeSet;}
vector<Vertex *> Graph::getVertexSet() const {return vertexSet;}

void Graph::addVertex(Vertex * newV) {vertexSet.push_back(newV);}
void Graph::addEdge(Edge *newE) {edgeSet.push_back(newE);}


Vertex* Graph::findVertex(const int id) const {  // CHANGEEEE


    for(int i=0;i<vertexSet.size();i++)
    {

        if(vertexSet[i]->getId()==id)
            return vertexSet[i];
    }

    //cout << "Vertex non existent";
    throw NonExistentVertex(id);
    //return 0x0;                               // CHANGE!!!!! THROW EXCEPTION
}
