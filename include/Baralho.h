#ifndef BARALHO_H
#define BARALHO_H

#include "../include/Carta.h"
#include "../include/Piloto.h"
#include "../include/Unidade.h"
#include "../include/Tatica.h"
#include "../include/Instantaneo.h"
#include "../include/Equipamento.h"

class Baralho {
private:
    void inicializaBaralho(Baralho& baralho);
public:
    int quantidade;
    std::vector<Carta*> cartas;
    std::string nome;
    int IDBaralho;

    Carta* seleciona_carta(int qtd);

    void verBaralho();

    void adiciona_carta(Carta* carta);

    int quantidade_cartas();

    Baralho();

    ~Baralho();
};

#endif