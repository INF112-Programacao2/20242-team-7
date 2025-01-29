#ifndef JOGADOR_H
#define JOGADOR_H

#include "../include/Carta.h"
#include "../include/Unidade.h"
#include "../include/Baralho.h"

class Jogador{
public:
    int vida;
    std::string nome;
    int qtdCalor;
    std::vector<Carta*> mao;
    std::vector<Carta*> pilha_descarte;
    std::vector<Carta*> campo;
    bool vezDeJogar;

    Jogador(int _vida, std::string _nome, int _qtdCalor, std::vector<Carta*> _mao, bool _vezDeJogar);
    void compra_carta(Carta* carta);
    void joga_carta(int ID);
    void declara_efeito(Carta* c);
    void descarta(const Carta* carta);
    void declara_ataque(Unidade atacante, Unidade defensora);

    void verMao();
    void verCampo();

    int getcalor();
    void setcalor(int _calor);
    int getVida();
    std::vector<Carta*> getMao();
    std::string getNome();
     
    
};
#endif
