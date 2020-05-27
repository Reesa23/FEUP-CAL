#ifndef FICHAJUNG_CLIENTE_H
#define FICHAJUNG_CLIENTE_H

#include <vector>
#include "Cabaz.h"
#include <string>
#include "Graph.h"
#include "Encomenda.h"


class Cliente  {
    vector<Encomenda> encomendas;
    Vertex *morada;
    string nif;
    string name;

public:
    string getName();
    string getNif();
    vector<Encomenda> getEncomendas();
    Vertex *getMorada();

    void setName(const string name);
    void setNif(const string nif);
    void setEncomendas(vector<Encomenda> newEncomendas);
    void setMorada(Vertex *v);

    void addEncomenda(Encomenda e);

    Cliente(string nome, string cNif, Vertex *cMorada, vector<Encomenda> cEncomendas);


};

class NonExistentClient{

    string nif;

public:

    NonExistentClient(string nifClient){ nif=nifClient; }
    // Operador << para mensagem de erro que apanha o objeto lançado pela exceção.
    friend ostream & operator<<(ostream &out, const NonExistentClient &nonExistentClient){
        out << "Client non existent! id: " << nonExistentClient.nif << endl;
        return out;
    }
};

#endif //FICHAJUNG_CLIENTE_H
