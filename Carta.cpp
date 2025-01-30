#include "Carta.h"
#include "Jogador.h"


int Carta::getID() {
    return ID;
}

int Carta::getCusto() {
    return Custo;
}

std::string Carta::getTipo() {
    return Tipo;
}

Carta::Carta(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
    : Descricao(_Desc), Tipo(_Tipo), Nome(_Nome), Custo(_Custo), ID(_ID) {}

Carta::~Carta() {} 

void Carta::gasta_calor(int custo, Jogador& jogador){
    jogador.setcalor(jogador.getcalor() - custo);
}
void Carta::gera_calor(int qtd, Jogador& jogador){
    jogador.setcalor(jogador.getcalor() + qtd);
}

 void Carta::fornece_efeito(){}



