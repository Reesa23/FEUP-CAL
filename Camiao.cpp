#include "Camiao.h"

using namespace std;

Camiao::Camiao(int newId, double volMax, double pesoMax) {
    id=newId;
    cVolmax=volMax;
    cPesomax=pesoMax;
}

bool Camiao::getAvailability() {return available;}
double Camiao::getCPesoMax() {return cPesomax;}
double Camiao::getCVolMax() {return cVolmax;}
vector<Cabaz> Camiao::getCabazes() { return carga;}
int Camiao::getId() {return id;}

void Camiao::setCVolmax(double cVolmax) {
    Camiao::cVolmax = cVolmax;
}

void Camiao::setCPesomax(double cPesomax) {
    Camiao::cPesomax = cPesomax;
}

void Camiao::setAvailability(bool av) {available=av;}

void Camiao::setId(int newId) {id = newId;}

void Camiao::addCabaz(Cabaz novoCabaz) {
    carga.push_back(novoCabaz);
  //  volumeAtual += novoCabaz.getVolume();   THROW EXCEPTION FOR WHEN CARGA ATUAL > CARGA MAX
    //pesoAtual += novoCabaz.getPeso();
}