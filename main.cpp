//
// Created by tisco on 18/05/2020.
//

#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "Graph.h"

Graph graph = Graph();

void createGraph()
{


    ifstream nodes("../resources/GridGraphs/4x4/nodes.txt");
    ifstream edges("../resources/GridGraphs/4x4/edges.txt");

    GraphViewer * gv = new GraphViewer(600, 600, false);
    gv->createWindow(600,600);

    string line;

    // VERTICES

    while(getline(nodes, line)) {
        int idn, x, y;
        char parenthesis, comma;

        stringstream ss(line);

        ss >> parenthesis >> idn >> comma >> x >> comma >> y;

        gv->addNode(idn, x, y);

        Vertex* tempV = new Vertex(idn, x, y);
        graph.addVertex(tempV);            // adds the vertices to the graph

        //delete tempV;

    }

    // EDGES

    int ide=0;

    while(getline(edges, line)) {
        int idn1, idn2;
        char parenthesis, comma, weight;

        stringstream ss(line);

        ss >> parenthesis >> idn1 >> comma >> idn2 >> comma >> weight;


        gv->addEdge(ide, idn1, idn2, EdgeType::DIRECTED);

        Edge *tempE = new Edge(ide, graph.findVertex(idn2),weight);
        graph.addEdge(tempE);

        ide++;
    }

    gv->rearrange();

    nodes.close();
    edges.close();
}


int main() {

    createGraph();

    //debug

    /*
    for(int i=0; i<graph.getVertexSet().size();i++)
    {
        cout<<"\n vertex "<<i<<": "<<graph.getVertexSet()[i]->getId();
    }

    for(int i=0; i<graph.getEdgeSet().size();i++)
    {
        cout<<"\n edge "<<i<<": "<<graph.getEdgeSet()[i]->getId();
    }*/

    getchar();
    return 0;
}
