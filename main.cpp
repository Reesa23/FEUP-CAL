#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "Graph.h"
#include "Cabaz.h"  // might not be needed here
#include "Camiao.h"  // might be needed here
#include "FarmFresh2U.h"

Graph graph = Graph();

GraphViewer * gv = new GraphViewer(600, 600, false); // new

void createGraph()
{

    ifstream nodes("../resources/GridGraphs/4x4/nodes.txt");
    ifstream edges("../resources/GridGraphs/4x4/edges.txt");

   // GraphViewer * gv = new GraphViewer(600, 600, false);
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
        int idn1, idn2, weight;
        char parenthesis, comma;


        stringstream ss(line);

        ss >> parenthesis >> idn1 >> comma >> idn2 >> comma >> weight;

        try
        {
            Edge *tempE;

            tempE = new Edge(ide, graph.findVertex(idn2),weight);
            graph.addEdge(tempE);

            gv->addEdge(ide, idn1, idn2, EdgeType::DIRECTED);

            graph.getVertexSet()[idn1]->addAdj(tempE);

            ide++;
        }

        catch (NonExistentVertex &n)
        {
            cout<<n;
        }

    }

    gv->rearrange();

    nodes.close();
    edges.close();
}

void MenuCliente(Cliente* &c, FarmFresh2U &f);
void verificaCliente(FarmFresh2U &f);
void displayClientinfo(Cliente* &c, FarmFresh2U &f);
void placeOrder(Cliente* &c, FarmFresh2U &f);
void MenuManager(FarmFresh2U &f);
void todaysTrails(FarmFresh2U &f);
void oneTruckMenu(FarmFresh2U &f);
void bestTrailMenu(FarmFresh2U &f);

void mainMenu(FarmFresh2U &f){

    cout<<"\n\n\t\t\tFarmFresh2U\n\n"<<endl;
    cout<<"Enter as:\n"<<endl;
    cout<<"{1} - Client"<<endl;
    cout<<"{2} - Manager"<<endl;
    cout<<"Press 0 to quit."<<endl;
    char op;
    cin>>op;
    switch(op) {
        case '1':
            verificaCliente(f);
            break;
        case '2':
            MenuManager(f);
            break;
        case '0':
            break;
        default:
            mainMenu(f);
            break;
    }
}

void verificaCliente(FarmFresh2U &f){

    cout << "Enter NIF:\n";
    Cliente *c;
    bool existe=false;
    string nif;
    cin >> nif;
    while(nif.size()>9 || nif.size()<9){
        cout<<"Invalid NIF! Try again:"<<endl;
        cin>>nif;
    }


    for(int i=0; i<f.getClientes().size();i++){
        if(f.getClientes()[i].getNif()==nif){
            existe=true;
            c=&f.getClientes()[i];
        }
    }
    while (!existe){
        cout<<"No client is registered with this NIF. Try again:"<<endl;
        cin >> nif;
        for(int i=0; i<f.getClientes().size();i++){
            if(f.getClientes()[i].getNif()==nif){
                existe=true;
                c=&f.getClientes()[i];

            }
        }
    }
    MenuCliente(c,f);


}

void MenuCliente(Cliente* &c, FarmFresh2U &f){

    cout<<endl;
    cout << "Entered as client!\n" << endl;
    cout << "{1} - See info" << endl;
    cout << "{2} - Place order" << endl;
    cout<< "Press 0 to return"<<endl;
    char op;
    cin >> op;
    switch (op) {
        case '1':
            displayClientinfo(c,f);
            break;
        case '2':
            placeOrder(c,f);
            break;
        case '0':
            mainMenu(f);
            break;
        default:
            MenuCliente(c, f);
            break;
    }
}

void displayClientinfo(Cliente* &c, FarmFresh2U &f){

    cout << endl;
    cout << "Selected - See information " << endl<<endl;
    cout << "Name: \t" << c->getName() << endl;
    cout << "Nif: \t" << c->getNif() << endl;
    cout << "Encomendas: " << endl;
    for(int j=0; j<c->getEncomendas().size();j++) {
        cout <<"            {"<<j+1<<"} - "<<c->getEncomendas()[j].getId() << endl;
    }
    cout << "Press 0 to return." << endl;
    char op;
    cin >> op;
    switch (op) {
        case '0':
            MenuCliente(c, f);
            break;
        default:
            displayClientinfo(c, f);
            break;

    }
}

void placeOrder(Cliente* &c, FarmFresh2U &f) {

    cout << "Choose the desired basket:" << endl;
    vector<Encomenda> enc;
    //vector<Cliente> cli;

    for (int i = 0; i < f.getCabazes().size(); i++) {
        cout << "{" << i << "}" << " - Basket "<<i+1<<":";
        cout <<"  "<<f.getCabazes()[i].getItens() << endl;
    }

    int op;
    cin >> op;
    cout<<f.getCabazes()[op].getId();

    Encomenda newEnc = Encomenda(f.getEncomendas().size()); //new order with next possible id
    newEnc.setClientNif(stoi(c->getNif()));
    newEnc.setCabaz(f.getCabazes()[op]);

    enc = c->getEncomendas();
    enc.push_back(f.getCabazes()[op].getId());

    c->setEncomendas(enc);

    f.findCliente(stoi(c->getNif())).setEncomendas(enc);
    f.addEncomenda(newEnc);

    //vector<Cliente> :: iterator it ;
    /*for(it=f.getClientes().begin();it!=f.getClientes().end();it++){
        if(it->getNif()==c.getNif()){
            cout<<endl<<it->getNif();
            f.getClientes().erase(it);
        }
    }*/
    //cli=f.getClientes();
    //cli.push_back(c);
    //f.setClientes(cli);
   // f.atualizaClienteFile();
    cout << "\nYour order was successfully placed!" << endl;
    cout << "Press 0 to return." << endl;
    cout << "Press any other key to order again." << endl;
    char op1;
    cin >> op1;
    switch (op1) {
        case '0':
            MenuCliente(c, f);
            break;
        default:
            placeOrder(c,f);
            break;

    }
}

void MenuManager(FarmFresh2U &f)
{
    cout<<endl;
    cout << "Entered as manager!\n" << endl;
    cout << "{1} - See today's trails - yet to be completed" << endl;
    cout << "{2} - Only one truck mode" << endl;
    cout << "{3} - Best trail simulation" << endl;
    cout<< "Press 0 to return"<<endl;
    char op;
    cin >> op;
    switch (op) {
        case '1':
            todaysTrails(f);
            break;
        case '2':
            oneTruckMenu(f);
            break;
        case '3':
            bestTrailMenu(f);
            break;
        case '0':
            mainMenu(f);
            break;
        default:
            MenuManager(f);
            break;
    }
}

void oneTruckMenu(FarmFresh2U &f)
{
    cout<<endl;
    cout << "Only one truck simulation\n" << endl<<endl;
    cout << "In this section we will consider only one truck and each lot it will have to take in order to deliever every order." << endl;
    cout<< "Press 0 to return"<<endl;

    // DISTIBUIR OS CABAZES PELO CAMIAO

    vector<Cabaz> cabazes = f.getCabazes();
    vector<Cabaz> remainingBaskets;// = cabazes;
    int counter=1;

    while (cabazes.size()>0) {
        Camiao tempCamiao = f.getFrotaDisponivel()[0];

        double volumeTotal = 0, pesoTotal = 0;

        int i = 0;

        while (volumeTotal < tempCamiao.getCVolMax() and pesoTotal < tempCamiao.getCPesoMax() and i < cabazes.size()) {
            if (volumeTotal + cabazes[i].getVolume() < tempCamiao.getCVolMax() and
                pesoTotal + cabazes[i].getPeso() < tempCamiao.getCPesoMax()) {
                tempCamiao.addCabaz(cabazes[i]);
                volumeTotal += cabazes[i].getVolume();
                pesoTotal += cabazes[i].getPeso();
            }
            else remainingBaskets.push_back(cabazes[i]); // caso nao entrem no lote

            i++;
        }

        cout << endl<<endl<<"Lot number " << counter << " will include the following baskets: ";
        for (int i = 0; i < tempCamiao.getCabazes().size(); i++) // primeiro lote
        {
            cout << endl << tempCamiao.getCabazes()[i].getId();
        }

        // dps fazer logo vários lotes e a cada volta do camião renovar o atributo carga para o novo lote
        counter++;
        cabazes.clear();
        cabazes=remainingBaskets;
        remainingBaskets.clear();
    }

    char op;
    cin >> op;
    switch (op) {
        case '0':
            MenuManager(f);
            break;
        default:
            oneTruckMenu(f);
            break;
    }

}


void todaysTrails(FarmFresh2U &f)
{
    cout<<endl;
    cout << "\"Selected - today's trails\n" << endl << endl;
    cout << "From " <<f.getFrota().size() << " total trucks today you have "<< f.getFrotaDisponivel().size() <<" available. " << endl;

    cout<< "Press 0 to return"<<endl;
    char op;
    cin >> op;
    switch (op) {
        case '0':
            MenuManager(f);
            break;
        default:
            todaysTrails(f);
            break;
    }
}

void bestTrailMenu(FarmFresh2U &f)
{
    cout<<endl;
    cout << "Best trail simulation\n" << endl<<endl;
    cout << "In this section we will calculate the shortest trail based on specific points of interest." << endl;
    cout << "In this case, we will consider that the orders must be delieverd in the houses in vertices 1 and 5 (our points of interest), while 0 being the farm (initial and final destination)." << endl;
    cout << "In a further implementation, the points of interest will be given by each order (which is associated with the client that will have the vertex of the house as an attribute)." << endl;


    vector<int> testing;

    testing.push_back(1);
    testing.push_back(5);

    graph.bestCircuit(0,0,testing);


    char op;
    cout<< "\nPress 0 to return"<<endl;
    cin >> op;
    switch (op) {
        case '0':
            MenuManager(f);
            break;
        default:
            bestTrailMenu(f);
            break;
    }

}

int main() {

    createGraph();

    /*vector<int> testing;

    testing.push_back(1);
    testing.push_back(5);

    graph.bestCircuit(0,0,testing);*/

    //---------------//

    FarmFresh2U company = FarmFresh2U(graph);
    mainMenu(company);


    getchar();
    return 0;
}
