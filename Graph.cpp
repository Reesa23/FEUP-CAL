#include "Graph.h"

using namespace std;

// VERTEX

Vertex::Vertex(int newId, double newX, double newY): id(newId), x(newX), y(newY) {}     // constructor

Vertex::~Vertex() {}

int Vertex::getId() const { return id;}
double Vertex::getDist() const { return dist;}
Vertex* Vertex::getPath() const { return path;}
vector<Edge*> Vertex::getAdj() const {return adj;}
bool Vertex::getVisited() const {return visited;}
int Vertex::getPrevPlace() const {return prevPlace;}
void Vertex::setVisited(bool v) {visited=v;}
void Vertex::setPrevPlace(int place) {prevPlace=place;}

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


Vertex* Graph::findVertex(int id) {


    for(int i=0;i<vertexSet.size();i++)
    {

        if(vertexSet[i]->getId()==id)
            return vertexSet[i];
    }

    throw NonExistentVertex(id);
}



void Graph::dijkstra(int initial_id) {


    MutablePriorityQueue<Vertex> pq;

    for (auto vertex : vertexSet) {
        vertex->setDist(999999);
        vertex->setPath(nullptr);
        vertex->setVisited(false);
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



double Graph::g(Vertex &start, Vertex &end, vector<Vertex*> &path)
{
    double dist;
    if(path.empty())
    {
        end.setPrevPlace(start.getId());
        dijkstra(start.getId());
        dist=end.getDist();
    }
    else if(path.size()==1)
    {
        path[0]->setPrevPlace(start.getId());
        dijkstra(start.getId());
        dist = path[0]->getDist();
        end.setPrevPlace(path[0]->getId());
        dijkstra(path[0]->getId());
        dist += end.getDist();
    }
    else
    {
        vector<double> distanceVec;
        for (int i = 0; i < path.size(); i++)
        {
            vector<Vertex*> subset;
            for (int j = 0; j < path.size(); j++)
            {
                if (i != j)
                {
                    subset.push_back(path[j]);
                }
            }
            dist = g(start,*path[i],subset);
            dijkstra(path[i]->getId());
            dist += end.getDist();
            distanceVec.push_back(dist);
        }

        vector<Vertex*> sub;

        dist = distanceVec[0];
        for(int i=0;i<distanceVec.size();i++)
        {
            if (distanceVec[i]<dist) dist=distanceVec[i];
        }


        for (int i = 0; i < distanceVec.size(); i++)
        {
            if (distanceVec[i] == dist)
            {
                for (int j = 0; j < path.size(); j++)
                {
                    if (i != j)
                    {
                        sub.push_back(path[j]);
                    }
                }
                g(start,*path[i],sub);
                end.setPrevPlace(path[i]->getId());
                break;
            }
        }
    }
    return dist;
}


void Graph::bestCircuit(int startVertexId, int endVertexId, vector<int> interestIds) {

    vector<Vertex*> interestVertices;

    for(int i=0;i<interestIds.size();i++)
    {
        interestVertices.push_back(findVertex(interestIds[i]));
    }

    double totalDistance;

    totalDistance = g(*findVertex(startVertexId),*findVertex(endVertexId),interestVertices);

    cout<<"\nTotal distance: "<< totalDistance<<endl;// <<" size:"<<interestVertices.size();

    vector<int> pathVertices;
    Vertex v = *vertexSet[endVertexId];

    while(v.getPath() != nullptr) {
        pathVertices.push_back(v.getPath()->getId());
        v = *v.getPath();
    }

    cout<<"Path: "<<startVertexId;
    for (int i=pathVertices.size()-1;i>=0;i--)
    {
        cout<<" -> "<<pathVertices[i];
    }
    cout<<" -> "<<endVertexId;

}
