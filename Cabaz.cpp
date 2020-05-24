#include "Cabaz.h"

Cabaz::Cabaz(double peso, double volume,string nomeDest, string morada, int numFatura)  {
    this->peso=peso;
    this->volume=volume;
    this->nomeDest=nomeDest;
    this->morada=morada;
    this->num_fatura=numFatura;
}

double Cabaz::getPeso() {
    return peso;
}

void Cabaz::setPeso(double peso) {
    Cabaz::peso = peso;
}

double Cabaz::getVolume() {
    return volume;
}

void Cabaz::setVolume(double volume) {
    Cabaz::volume = volume;
}

string Cabaz::getNomeDest() {
    return nomeDest;
}

void Cabaz::setNomeDest(string nomeDest) {
    Cabaz::nomeDest = nomeDest;
}

string Cabaz::getMorada()  {
    return morada;
}

void Cabaz::setMorada(string morada) {
    Cabaz::morada = morada;
}

int Cabaz::getNumFatura()  {
    return num_fatura;
}

void Cabaz::setNumFatura(int numFatura) {
    num_fatura = numFatura;
}

int Cabaz::getId() const {
    return id;
}

void Cabaz::setId(int id) {
    Cabaz::id = id;
}
