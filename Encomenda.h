#ifndef FICHAJUNG_ENCOMENDA_H
#define FICHAJUNG_ENCOMENDA_H

#include "Cabaz.h"

class Encomenda {

    int id;
    int clientNif;
    Cabaz cabaz;

public:

    Encomenda(int eId);
    Encomenda(int eId, int nif, Cabaz eCabaz);

    int getId();
    Cabaz getCabaz();
    int getClientNif();

    void setId(int newId);
    void setClientNif(int clientNif);
    void setCabaz(Cabaz newCabaz);

};

class NonExistentOrder{

    string id;

public:

    NonExistentOrder(int idE){ id=idE; }
    // Operador << para mensagem de erro que apanha o objeto lançado pela exceção.
    friend ostream & operator<<(ostream &out, const NonExistentOrder &nonExistentOrder){
        out << "Order non existent! id: " << nonExistentOrder.id << endl;
        return out;
    }
};

#endif //FICHAJUNG_ENCOMENDA_H
