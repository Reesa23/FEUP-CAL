#ifndef FICHAJUNG_CAMIAO_H
#define FICHAJUNG_CAMIAO_H

#include "Cabaz.h"

using namespace std;

class Camiao {
    int id;
    double cVolmax;
    double cPesomax;

    bool available = false;

   // double volumeAtual;
   // double pesoAtual;

    vector<Cabaz> carga;

public:
    Camiao(int newId, double volMax, double pesoMax);

    int getId();
    bool getAvailability();
    double getCVolMax();
    double getCPesoMax();
    vector<Cabaz> getCabazes();
    void setCVolmax(double cVolmax);
    void setCPesomax(double cPesomax);
    void setAvailability(bool av);
    void setId(int newId);
    void addCabaz(Cabaz novoCabaz);
};


#endif //FICHAJUNG_CAMIAO_H
