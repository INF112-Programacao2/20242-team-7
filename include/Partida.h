#ifndef PARTIDA_H
#define PARTIDA_H

#include "../include/Jogador.h"
#include "../include/Baralho.h"

class Partida {
private:
    Jogador j1;
    Jogador j2;
    bool fim = false;

public:
    int tempo;
    int rodada;
    std::string historico;
    int turno;
    
    Partida();
    Partida(std::string nome_j1, std::string nome_j2);
    ~Partida() = default;

    bool encerra_partida(bool _fim = false);

    //void exibe_historico();

    void passa_turno();
    int getTurno();
};

#endif