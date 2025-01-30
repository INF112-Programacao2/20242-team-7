#ifndef TATICA_H
#define TATICA_H

#include "Carta.h"
#include "Unidade.h"
#include <string>



class Tatica : virtual public Carta{
    public:
        virtual void fornece_efeito(Unidade unidade, Jogador jogador);
        Tatica(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
};
#endif