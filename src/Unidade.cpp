#include "../include/Unidade.h"
#include "../include/Piloto.h"

Unidade::Unidade()
    : Carta("", "", "", 0, 0), Atk(0), Def(0), Hp(0), Equip(false), Guarda(false), Evasao(false) {}

Unidade::Unidade(int _Atk, int _Def, int _Hp, int _Custo, std::string _Desc, std::string _Tipo, std::string _Nome, bool _Equip, int _ID, bool _guarda)
    : Carta(_Desc, _Tipo, _Nome, _Custo, _ID), Atk(_Atk), Def(_Def), Hp(_Hp), Equip(_Equip), Guarda(_guarda), Evasao(false)  {}

Unidade::Unidade(int _Atk, int _Def, int _Hp, int _Custo, std::string _Desc, std::string _Tipo, std::string _Nome, bool _Equip, int _ID, bool _guarda, int _calor_produzido)
    : Carta(_Desc, _Tipo, _Nome, _Custo, _ID),
    Atk(_Atk),
    Def(_Def),
    Hp(_Hp),
    Equip(_Equip),
    Guarda(_guarda),
    calor_produzido(_calor_produzido)  {}

void Unidade::receberDano(int dano){
    if(!Evasao){
        Hp -= dano;
        if(Hp<0)
        Hp=0;
    }
}

void Unidade::Atacar(Unidade &Outra){
        Outra.receberDano(Atk);
}

bool Unidade::isEquiped(){
    return Equip;
}

void Unidade::le() const {
    std::cout <<"Ataque : "<< Atk<< std::endl 
    << "HP : " << Hp << std::endl 
    << "Descricao :" << Descricao << std::endl 
    << "Tipo :" <<Tipo << std::endl
    <<"Nome : "<< Nome << std::endl 
    << "Piloto:"<< getPiloto()->getNome() << std::endl;
}

/*GETTERS E SETTERS*/
/*Getters*/
Piloto* Unidade::getPiloto() const{
    return pilotoAssociado;
}

int Unidade::getHp(){
    return Hp;
}

int Unidade::getAtk(){
    return Atk;
}

int Unidade::getDef(){
    return Def;
}

/*Setters*/
void Unidade::setPiloto(Piloto* piloto){
    pilotoAssociado = piloto;
}

bool Unidade::getEvasao(){
    return Evasao;
}

void Unidade::setHp(int _hp){
    Hp = _hp;
}

void Unidade::ativaEvasao(){
    Evasao=true;
}

void Unidade::setAtk(int _Atk) {
    Atk = _Atk;
}

void Unidade::ativa_guarda(){
    Guarda = true;
}
