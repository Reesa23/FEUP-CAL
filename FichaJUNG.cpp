#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>


void exercicio3()
{

    ifstream nodes("../resources/GridGraphs/4x4/nodes.txt");
    ifstream edges("../resources/GridGraphs/4x4/edges.txt");

    GraphViewer * gv = new GraphViewer(600, 600, false);
    gv->createWindow(600,600);

    string line;
    while(getline(nodes, line)) {
        int idn, x, y;
        char parenthesis, comma;

        stringstream ss(line);

        ss >> parenthesis >> idn >> comma >> x >> comma >> y;

        gv->addNode(idn, x, y);
    }

    int ide=0;

    while(getline(edges, line)) {
        int idn1, idn2;
        char parenthesis, comma;

        stringstream ss(line);

        ss >> parenthesis >> idn1 >> comma >> idn2;


        gv->addEdge(ide, idn1, idn2, EdgeType::UNDIRECTED);
        ide++;
    }

/*
    string line;
    while(getline(nodes, line)) {
        int idn, x, y;
        char semicolon;

        stringstream ss(line);

        ss >> idn >> semicolon >> x >> semicolon >> y;

        gv->addNode(idn, x, y);
    }

    while(getline(edges, line)) {
        int ide, idn1, idn2;
        char semicolon;

        stringstream ss(line);

        ss >> ide >> semicolon >> idn1 >> semicolon >> idn2;

        gv->addEdge(ide, idn1, idn2, EdgeType::UNDIRECTED);
    }
*/

    gv->rearrange();

    nodes.close();
    edges.close();
}

int main() {

	exercicio3();

	getchar();
	return 0;
}
