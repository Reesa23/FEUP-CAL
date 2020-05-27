#ifndef FICHAJUNG_CABAZ_H
#define FICHAJUNG_CABAZ_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Cabaz {
    double peso;
    double volume;
    string nomeDest;
    string morada;
    int id;
    string itens;
public:

    Cabaz(double peso, double volume,string nomeDest,string morada, int numFatura);

    Cabaz();

    double getPeso() ;

    void setPeso(double peso);

    string getItens() ;

    void setItens( string itens);

    int getId() ;

    double getVolume() ;

    void setVolume(double volume);

    string getNomeDest() ;

    void setId(int id);

    void setNomeDest(string nomeDest);

     string getMorada() ;

    void setMorada( string morada);



};


class NonExistentCabaz{

    string id;

public:

    NonExistentCabaz(string idC){ id=idC; }
    // Operador << para mensagem de erro que apanha o objeto lançado pela exceção.
    friend ostream & operator<<(ostream &out, const NonExistentCabaz &nonExistentCabaz){
        out << "Basket non existent! id: " << nonExistentCabaz.id << endl;
        return out;
    }
};

#endif //FICHAJUNG_CABAZ_H
