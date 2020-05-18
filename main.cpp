//
// Created by tisco on 18/05/2020.
//

#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include "Graph.h"

void createGraph()
{

    Graph graph = Graph();

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
        char parenthesis, comma;

        stringstream ss(line);

        ss >> parenthesis >> idn1 >> comma >> idn2;


        gv->addEdge(ide, idn1, idn2, EdgeType::UNDIRECTED);

        Edge tempE = Edge(ide, graph.findVertex(idn2),1.0);
        graph.addEdge(&tempE);

        ide++;
    }

    gv->rearrange();

    nodes.close();
    edges.close();
}


int main() {

    createGraph();

    getchar();
    return 0;
}
