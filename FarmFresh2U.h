#ifndef FICHAJUNG_FARMFRESH2U_H
#define FICHAJUNG_FARMFRESH2U_H

#include "Cliente.h"
#include "Camiao.h"
#include "Encomenda.h"
#include "Graph.h"


class FarmFresh2U {
    vector<Camiao> frota;
    vector<Camiao> frotaDisponivel;
    vector<Cliente> clientes;
    vector<Encomenda> encomendas;
    vector<Cabaz> cabazes;


public:
    FarmFresh2U(Graph g);
    vector<Cliente> getClientes();
    vector<Camiao> getFrota();
    vector<Camiao> getFrotaDisponivel();
    vector<Cabaz>getCabazes();
    vector<Encomenda> getEncomendas();



  //  vector<Entregador> getEntregadores();

   // void atualizaClienteFile();
    void encomendaReadfile();
    void clienteReadfile(Graph g);
    void cabazReadfile();
    void camiaoReadfile();
    vector<Encomenda> readEncomendas(string encomendas);

    void addEncomenda(Encomenda enc);

    Cabaz findCabaz(int id); // finds basket based on its id
    Encomenda findEncomenda(int id); // finds order based on its id
    Cliente findCliente(int nif); // finds client based on his nif


    void setClientes(vector<Cliente> clientes);

    //void setEntregadores(vector<Entregador> entregadores);

    void setCabazes(vector<Cabaz> cabazes);
    void addFrota(Camiao camiao); // ver disponibilidade, se sim ent dar add à frotaDisponivel


};



#endif //FICHAJUNG_FARMFRESH2U_H
