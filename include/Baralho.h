#ifndef BARALHO_H
#define BARALHO_H

#include "Carta.h"

class Baralho {
public:
    int quantidade;
    std::vector<Carta*> cartas;
    std::string nome;
    int IDBaralho;

    void inicializaBaralho(Baralho& baralho);
    Carta* seleciona_carta(int qtd);

    void adiciona_carta(Carta* carta);

    int quantidade_cartas();

    ~Baralho();
};

#endif