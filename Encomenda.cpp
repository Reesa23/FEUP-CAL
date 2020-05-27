#include "Encomenda.h"

Encomenda::Encomenda(int eId) {id=eId;}
Encomenda::Encomenda(int eId, int nif, Cabaz eCabaz) {
    id=eId;
    clientNif=nif;
    cabaz=eCabaz;
}

int Encomenda::getId() {return id;}
Cabaz Encomenda::getCabaz() { return cabaz;}
int Encomenda::getClientNif() {return clientNif;}

void Encomenda::setId(int newId) {id= newId;}
void Encomenda::setClientNif(int nifClient) {clientNif = nifClient;}
void Encomenda::setCabaz(Cabaz newCabaz) {cabaz = newCabaz;}