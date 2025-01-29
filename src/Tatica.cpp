#include "../include/Tatica.h"
#include "../include/Jogador.h"

Tatica::Tatica(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
    :Carta (_Desc, _Tipo, _Nome, _Custo, _ID){}

    void Tatica::fornece_efeito(Unidade unidade, Jogador jogador){}


