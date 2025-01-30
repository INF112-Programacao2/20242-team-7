#ifndef BARALHO_H
#define BARALHO_H

#include "Carta.h"
#include "vector"
#include "string"

class Baralho{
    private:
        int quantidade;
        std::vector<Carta> lista;
        std::string nome;
        int IDbaralho;
    public:
        Carta seleciona_carta(int qtd);
        void adiciona_carta();
};
#endif