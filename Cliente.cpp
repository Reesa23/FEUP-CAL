#include "Cliente.h"


string Cliente::getName()  {return name;}
string Cliente::getNif() {return nif;}
vector<Encomenda> Cliente::getEncomendas() {return encomendas;}
Vertex *Cliente::getMorada() {return morada;}

void Cliente::setName(string name) {Cliente::name = name;}
void Cliente::setNif(const string nif) {Cliente::nif = nif;}
void Cliente::setEncomendas(vector<Encomenda> newEncomendas) {encomendas = newEncomendas;}
void Cliente::setMorada(Vertex *v) {morada=v;}

void Cliente::addEncomenda(Encomenda e) {encomendas.push_back(e);}

Cliente::Cliente(string nome, string cNif, Vertex *cMorada, vector<Encomenda> cEncomendas) {
    name=nome;
    nif=cNif;
    morada=cMorada;
    encomendas=cEncomendas;
}


