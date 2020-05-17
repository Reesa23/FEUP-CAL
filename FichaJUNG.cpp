#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>


void exercicio3()
{
    ifstream nodes("../resources/mapa1/nos.txt");
    ifstream edges("../resources/mapa1/arestas.txt");

    GraphViewer * gv = new GraphViewer(600, 600, false);
    gv->createWindow(600,600);

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


    gv->rearrange();

    nodes.close();
    edges.close();
}

int main() {

	exercicio3();

	getchar();
	return 0;
}
