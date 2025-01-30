#include "Unidade.h"

int Unidade::getHp(){
    return Hp;
}

int Unidade::getAtk(){
    return Atk;
}

int Unidade::getDef(){
    return Def;
}

Unidade::Unidade(int _Atk, int _Def, int _Hp, int _Custo, std::string _Desc, std::string _Tipo, std::string _Nome, bool _Equip, int _ID, bool _guarda)
    : Carta(_Desc, _Tipo, _Nome, _Custo, _ID), Atk(_Atk), Def(_Def), Hp(_Hp), Equip(_Equip), Guarda(_guarda)  {}


void Unidade::receberDano(int dano){
    Hp -= dano;
    if(Hp<0)
        Hp=0;
}

void Unidade::Atacar(Unidade &Outra){
    int dano = Atk - Outra.getDef();
    if(dano>0){
        Outra.receberDano(dano);
    }
}

bool Unidade::isEquiped(){
    return Equip;
}

void Unidade::setHp(int _hp){
    Hp = _hp;
}

void Unidade::le()const {
    std::cout<<Atk<<std::endl<<Def<<std::endl<<Hp<<std::endl<<Descricao<<std::endl<<Tipo<<std::endl<<Nome<<std::endl<<Equip<<std::endl;
}

void Unidade::setAtk(int _Atk) {
    Atk = _Atk;
}

void Unidade::ativa_guarda(){
    Guarda = true;
}

