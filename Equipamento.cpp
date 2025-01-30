#include "Equipamento.h"
#include "Jogador.h"
#include "Unidade.h"


Equipamento::Equipamento(int atk_extra, int hp_extra, bool _guarda, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
: Carta(_Desc, _Tipo, _Nome, _Custo, _ID), 
Tatica(_Desc, _Tipo, _Nome, _Custo, _ID),
hpextra(hp_extra),
atkextra(atk_extra),
guarda(_guarda){
} 

void Equipamento::fornece_efeito(Unidade unidade, Jogador jogador){
    unidade.setAtk(unidade.getAtk() + atkextra);
    unidade.setHp(unidade.getHp() + hpextra);
    if(guarda){
        unidade.ativa_guarda();
        jogador.setcalor(jogador.getcalor() + 1);
    }
}
