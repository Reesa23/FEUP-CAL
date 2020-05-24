#ifndef FICHAJUNG_CABAZ_H
#define FICHAJUNG_CABAZ_H

#include "string"
 using namespace std;

class Cabaz {
    double peso;
    double volume;
    string nomeDest;
    string morada;
    int num_fatura;
    int id;
public:

    Cabaz(double peso, double volume,string nomeDest,string morada, int numFatura);

    double getPeso() ;

    void setPeso(double peso);

    int getId() const;

    void setId(int id);

    double getVolume() ;

    void setVolume(double volume);

    string getNomeDest() ;

    void setNomeDest(string nomeDest);

     string getMorada() ;

    void setMorada( string morada);

    int getNumFatura();

    void setNumFatura(int numFatura);
};


#endif //FICHAJUNG_CABAZ_H
