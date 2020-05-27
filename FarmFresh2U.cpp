#include <fstream>
#include <iostream>
#include "FarmFresh2U.h"

using namespace std;

FarmFresh2U::FarmFresh2U(Graph g) {  // completar no fim com todos os readFiles
    cabazReadfile();
    cout<<"cabaz";
    camiaoReadfile();
    cout<<"camiao";
    encomendaReadfile();
    cout<<"encomenda";
    clienteReadfile(g);
    cout<<"cliente";
}

vector<Encomenda> FarmFresh2U::readEncomendas(string encomendasStr)
{
    cout<<"oi";
    string temp;
    vector<Encomenda> encomendas_temp;

    cout<<endl<<encomendasStr.length();
    for (size_t i = 0; i <= encomendasStr.length(); i++)
    {
        if (encomendasStr[i] == ',' )
        {
            i++;
            encomendas_temp.push_back(findEncomenda(stoi(temp)));
            temp = "";
        }
        else
            temp += encomendasStr[i];
    }
    encomendas_temp.push_back(findEncomenda(stoi(temp)));
    cout<<"finished this";
    return encomendas_temp;

}
/*
void FarmFresh2U:: encomendaReadfile(){  // lê o file das encomendas

    Encomenda e;
    vector<string> cliente_info;
    ifstream infile;
    string line;
    infile.open("../files/encomendas.txt");
    while(getline(infile,line)){
        if(line=="------"){
            e.setId(cliente_info[0]);
            e.setCabaz(cliente_info[1]);
            e.setCliente(cliente_info[2]);
            clientes.push_back(e);
            cliente_info.clear();
        }else{
            cliente_info.push_back(line);
        }
    }
    e.setName(cliente_info[0]);
    e.setNif(cliente_info[1]);
    e.setCliente(cliente_info[2]);
    clientes.push_back(e);
    cliente_info.clear();
    return;
}*/

void FarmFresh2U:: clienteReadfile(Graph g){

   // Cliente* c;
    string tempName, tempNif;
    Vertex *tempAddress;
    vector<Encomenda> testingEncomenda;
    vector<string> cliente_info;
    ifstream infile;
    string line;
    infile.open("../files/clientes.txt");
    while(getline(infile,line)){
        if(line=="------"){

            tempName = cliente_info[0];  // client's name
            tempAddress = g.findVertex(stoi(cliente_info[1]));  // client's address (correspondent vertex)
            tempNif = cliente_info[2];  // client's nif
            testingEncomenda = readEncomendas(cliente_info[3]);
            clientes.push_back(Cliente(tempName,tempNif,tempAddress,testingEncomenda));
            cliente_info.clear();
        }else{
            cliente_info.push_back(line);
        }
    }
    tempName = cliente_info[0];  // client's name
    tempAddress = g.findVertex(stoi(cliente_info[1]));  // client's address (correspondent vertex)
    tempNif = cliente_info[2];  // client's nif
    testingEncomenda = readEncomendas(cliente_info[3]);
    clientes.push_back(Cliente(tempName,tempNif,tempAddress,testingEncomenda));
    cliente_info.clear();
}


void FarmFresh2U:: cabazReadfile(){

    Cabaz c;
    vector<string> cliente_info;
    ifstream infile;
    string line;
    infile.open("../files/cabazes.txt");
    while(getline(infile,line)){
        if(line=="------"){
            c.setId(stoi(cliente_info[0]));
            c.setPeso(stod(cliente_info[1]));
            c.setVolume(stod(cliente_info[2]));
            c.setItens(cliente_info[3]);
            cabazes.push_back(c);
            cliente_info.clear();
        }else{
            cliente_info.push_back(line);
        }
    }
    c.setId(stoi(cliente_info[0]));
    c.setPeso(stod(cliente_info[1]));
    c.setVolume(stod(cliente_info[2]));
    c.setItens(cliente_info[3]);
    cabazes.push_back(c);
    cliente_info.clear();
    return;
}


void FarmFresh2U:: camiaoReadfile(){

    //Camiao *c;
    vector<string> parameters;
    vector<string> camiao_info;
    ifstream infile;
    string line;
    infile.open("../files/camioes.txt");
    while(getline(infile,line)){
        if(line=="------"){
            parameters.push_back(camiao_info[0]);
            parameters.push_back(camiao_info[1]);
            parameters.push_back(camiao_info[2]);
            parameters.push_back(camiao_info[3]);

            Camiao tempC = Camiao(stoi(parameters[0]), stod(parameters[1]), stod(parameters[2]));

            if(camiao_info[3]=="1") {
                tempC.setAvailability(true);
                frotaDisponivel.push_back(tempC);
            }
            frota.push_back(tempC);

            camiao_info.clear();
            parameters.clear();
        }else{
            camiao_info.push_back(line);
        }
    }

    parameters.push_back(camiao_info[0]);
    parameters.push_back(camiao_info[1]);
    parameters.push_back(camiao_info[2]);
    parameters.push_back(camiao_info[3]);

    Camiao tempC = Camiao(stoi(parameters[0]), stod(parameters[1]), stod(parameters[2]));

    if(camiao_info[3]=="1") {

        tempC.setAvailability(true);
        frotaDisponivel.push_back(tempC);
    }
    frota.push_back(tempC);

    return;
}

void FarmFresh2U:: encomendaReadfile(){

//    Encomenda *e;
    int tempId, tempNif;
    Cabaz tempCabaz;

    vector<string> encomenda_info;
    Cabaz c;
    Cliente *cli;
    ifstream infile;
    string line;
    infile.open("../files/encomendas.txt");
    while(getline(infile,line)){
        if(line=="------"){
            tempId = stoi(encomenda_info[0]);
            tempCabaz = findCabaz(stoi(encomenda_info[1]));
            tempNif = stoi(encomenda_info[2]);
            encomendas.push_back(Encomenda(tempId, tempNif, tempCabaz));
            encomenda_info.clear();
        }else{
            encomenda_info.push_back(line);
        }
    }
    tempId = stoi(encomenda_info[0]);
    tempCabaz = findCabaz(stoi(encomenda_info[1]));
    tempNif = stoi(encomenda_info[2]);
    encomendas.push_back(Encomenda(tempId, tempNif, tempCabaz));
    encomenda_info.clear();
    return;
}


/*void FarmFresh2U:: atualizaClienteFile(){
    clienteReadfile();
    ofstream file;
    string b="";
    file.open("../files/clientes.txt");
    for(int i=0; i<clientes.size()-1;i++){
        string a="";
       file<< clientes[i].getName()<<endl;
        file<< clientes[i].getNif()<<endl;
        for(int j=0; j<clientes[i].getEncomendas().size()-1;j++){
            a+=clientes[i].getEncomendas()[j]+", ";
        }
        a+=clientes[i].getEncomendas()[clientes[i].getEncomendas().size()-1];
        file<<a<<endl;
        file << "------" << endl;
    }
    file << clientes[clientes.size() - 1].getName() << endl;
    file << clientes[clientes.size() - 1].getNif() << endl;
    for(int j=0; j<clientes[clientes.size() - 1].getEncomendas().size();j++){
        b+=clientes[clientes.size() - 1].getEncomendas()[j]+", ";
    }
    b+=clientes[clientes.size() - 1].getEncomendas()[clientes[clientes.size() - 1].getEncomendas().size()-1];
    file<<b;


}*/



Cabaz FarmFresh2U::findCabaz(int id) {
    for(int i=0;i<cabazes.size();i++)
    {
        if(cabazes[i].getId()==id)
            return cabazes[i];
    }

    throw NonExistentCabaz(to_string(id));

}

Encomenda FarmFresh2U::findEncomenda(int id) {
    for(int i=0;i<encomendas.size();i++)
    {
        if(id==encomendas[i].getId())
            return encomendas[i];
    }
    throw NonExistentOrder(id); // CREATE
}

Cliente FarmFresh2U::findCliente(int nif) {
    for(int i=0;i<clientes.size();i++)
    {
        if(clientes[i].getNif()==to_string(nif))
            return clientes[i];
    }
    throw NonExistentClient(to_string(nif));
}

vector<Cliente> FarmFresh2U::getClientes()  {
    return clientes;
}

 vector<Cabaz> FarmFresh2U::getCabazes()  {return cabazes;}
 vector<Encomenda> FarmFresh2U::getEncomendas() {return encomendas;}

 void FarmFresh2U::addEncomenda(Encomenda enc) {encomendas.push_back(enc);}

void FarmFresh2U::setClientes( vector<Cliente> clientes) {
    FarmFresh2U::clientes = clientes;
}


void FarmFresh2U::setCabazes( vector<Cabaz> cabazes) {
    FarmFresh2U::cabazes = cabazes;
}

vector<Camiao> FarmFresh2U::getFrota() {return frota;}

vector<Camiao> FarmFresh2U::getFrotaDisponivel() {return frotaDisponivel;}

void FarmFresh2U::addFrota(Camiao camiao) {
    frota.push_back(camiao);
    if(camiao.getAvailability()==true) frotaDisponivel.push_back(camiao);
}