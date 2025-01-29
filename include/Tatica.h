#ifndef TATICA_H
#define TATICA_H

#include "../include/Carta.h"
#include "../include/Unidade.h"
#include <string>



// Forward declaration
class Unidade; // Apenas declara que Unidade existe



class Tatica : virtual public Carta{
    public:        
        Tatica(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
        virtual void fornece_efeito(Unidade* unidade, Jogador jogador);
};
#endif