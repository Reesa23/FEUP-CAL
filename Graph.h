#ifndef FICHAJUNG_GRAPH_H
#define FICHAJUNG_GRAPH_H


#include <vector>
#include <queue>
#include <list>
#include <limits>
#include <cmath>
#include <iostream>
#include "MutablePriorityQueue.h"

using namespace std;

class Edge;
class Graph;
class Vertex;


/************************* Vertex  **************************/


class Vertex {
    int id;						// vertex id
    double x;                   // x coordinate
    double y;                   // y coordinate
    vector<Edge*> adj;           // outgoing edges

    double dist = 0;
    Vertex* path = nullptr;
    int prevPlace = -1;
    int queueIndex = 0; 		// required by MutablePriorityQueue

    bool visited = false;		// auxiliary field
    //bool processing = false;	// auxiliary field

    //void addEdge(Vertex *dest, double w);


public:
    Vertex(int newId, double newX, double newY);
    ~Vertex();

    int getId() const;
    double getDist() const;
    Vertex *getPath() const;
    vector<Edge*> getAdj() const;
    bool getVisited() const;
    int getPrevPlace() const;

    void setDist(double distance);
    void setPath(Vertex *newPath);
    void addAdj(Edge *edge);
    void setVisited(bool v);
    void setPrevPlace(int placeId);

    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
    //friend class Graph;
    friend class MutablePriorityQueue<Vertex>;


};



// ?  Vertex::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
/*
void Vertex::addEdge(Vertex *d, double w) {
    adj.push_back(Edge(d, w));
}

bool Vertex::operator<(Vertex& vertex) const {
    return this->dist < vertex.dist;
}

Vertex::getInfo() const {
    return this->info;
}

double Vertex<T>::getDist() const {
    return this->dist;
}

Vertex *Vertex::getPath() const {
    return this->path;
}*/

/********************** Edge  ****************************/

class Edge {
    int id;
    Vertex* dest;      // destination vertex
    double weight;     // edge weight

public:
    Edge(int newId, Vertex* d, double w);
    int getId();
    Vertex* getDest();
    double getWeight();
    void updateWeight(double newWeight);

    friend class Graph;
    friend class Vertex;
};



/*************************** Graph  **************************/

class Graph {
    vector<Vertex *> vertexSet;    // vertex set
    vector<Edge*> edgeSet;         // edge set

public:
    Vertex *findVertex(int id);
    //bool addVertex(const T &in);
    //bool addEdge(const T &sourc, const T &dest, double w);

    Graph();
    int getNumVertex() const;
    vector<Vertex *> getVertexSet() const;
    vector<Edge *> getEdgeSet() const;
    void addVertex(Vertex* newV);
    void addEdge(Edge* newE);

    void bestCircuit(int startVertexId, int endVertexId, vector<int> interestIds);
    double g(Vertex &start, Vertex &end, vector<Vertex*> &path);

    void dijkstra(int initial_id);
};


class NonExistentVertex{

    int id;

public:

    NonExistentVertex(int idV){ id= idV; }
    // Operador << para mensagem de erro que apanha o objeto lançado pela exceção.
    friend ostream & operator<<(ostream &out, const NonExistentVertex &nonExistentVertex){
        out << "Vertex non existent! id: " << nonExistentVertex.id << endl;
        return out;
    }
};


/* CLASS STUFF, MIGHT BE USEFUL LATER
 *
 *
 *
 *
    // Fp05 - single source
    void unweightedShortestPath(const T &s);    //TODO...
    void dijkstraShortestPath(const T &s);      //TODO...
    void bellmanFordShortestPath(const T &s);   //TODO...
    vector<T> getPathTo(const T &dest) const;   //TODO...

    // Fp05 - all pairs
    void floydWarshallShortestPath();   //TODO...
    vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;   //TODO...

};

template <class T>
int Graph<T>::getNumVertex() const {
    return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
    return vertexSet;
}
*/
/*
 * Auxiliary function to find a vertex with a given content.
 */
/*
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}
*/
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
/*
template <class T>
bool Graph<T>::addVertex(const T &in) {
    if ( findVertex(in) != NULL)
        return false;
    vertexSet.push_back(new Vertex<T>(in));
    return true;
}
*/
/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
/*
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == NULL || v2 == NULL)
        return false;
    v1->addEdge(v2,w);
    return true;
}

*/
/**************** Single Source Shortest Path algorithms ************/
/*
template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {


}


template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
    // TODO
}

*/



#endif //FICHAJUNG_GRAPH_H
