#include "../include/Equipamento.h"
#include "../include/Jogador.h"
#include "../include/Unidade.h"

// Construtor da classe Equipamento, inicializa os atributos e chama os construtores das classes base
Equipamento::Equipamento(int atk_extra, int hp_extra, bool _guarda, int _calor_extra, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
: Carta(_Desc, _Tipo, _Nome, _Custo, _ID), 
Tatica(_Desc, _Tipo, _Nome, _Custo, _ID),
hpextra(hp_extra),
atkextra(atk_extra),
guarda(_guarda),
calor_extra(_calor_extra){} 

// Construtor da classe Equipamento, inicializa os atributos e chama os construtores das classes base
Equipamento::Equipamento(int atk_extra, int hp_extra, bool _guarda, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
: Carta(_Desc, _Tipo, _Nome, _Custo, _ID), 
Tatica(_Desc, _Tipo, _Nome, _Custo, _ID),
hpextra(hp_extra),
atkextra(atk_extra),
guarda(_guarda) {} 

// Método que aplica os efeitos do equipamento a uma unidade e a um jogador
void Equipamento::fornece_efeito(Unidade* unidade, Jogador jogador){
    // Aumenta o ataque da unidade
    unidade->setAtk(unidade->getAtk() + atkextra);
    // Aumenta a vida da unidade
    unidade->setHp(unidade->getHp() + hpextra);
    // Se o equipamento tiver a habilidade de guarda, ativa a guarda na unidade
    if(guarda){
        unidade->ativa_guarda();
    }
    // Aumenta o calor do jogador com base no calor extra do equipamento, por padrão é 0
    jogador.setcalor(jogador.getcalor() + calor_extra);
}