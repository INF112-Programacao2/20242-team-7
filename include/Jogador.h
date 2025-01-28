#ifndef JOGADOR_H
#define JOGADOR_H

#include "Carta.h"
#include "Baralho.h"
#include "Unidade.h"

class Jogador{
public:
    int vida;
    std::string nome;
    std::vector<Carta*> mao;
    int qtdCalor;
    std::vector<Carta*> pilha_descarte;
    std::vector<Carta*> campo;
    bool vezDeJogar;

    Jogador(int _vida, std::string _nome, int _qtdCalor, std::vector<Carta*> _mao, bool _vezDeJogar);
    void compra_carta(Carta* carta);
    void joga_carta(int ID);
    void declara_efeito(Carta* c);
    void encerra_turno();
    void descarta(const Carta* carta);
    void verMao();
    void iniciarMao(Baralho baralho);

    void declara_ataque(Unidade atacante, Unidade defensora);
    int getcalor();
    void setcalor(int _calor);
    int getVida();
    std::vector<Carta*> getMao();
    std::string getNome();
     
    
};
#endif
