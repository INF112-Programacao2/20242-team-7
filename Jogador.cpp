#include "Jogador.h"


void Jogador::declara_ataque(Unidade atacante, Unidade defensora){
    atacante.Atacar(defensora);
}

int Jogador::getcalor(){
    return qtdCalor;
}
void Jogador::setcalor(int _calor){
    qtdCalor = _calor;
}







