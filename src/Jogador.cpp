#include "../include/Jogador.h"
#include <algorithm>

Jogador::Jogador(int _vida, std::string _nome, int _qtdCalor, std::vector<Carta*> _mao, bool _vezDeJogar)
    : vida(_vida), nome(_nome), qtdCalor(_qtdCalor), mao(_mao), vezDeJogar(_vezDeJogar) {}

//Funcoes de acao do jogador

void Jogador::compra_carta(Carta* carta) {
    mao.push_back(carta);
}

void Jogador::joga_carta(int indice) {
    if (indice >= 0 && indice < mao.size()) {
        Carta* carta = mao[indice];
        campo.push_back(carta);
        mao.erase(mao.begin() + indice);
    }
}

//Funcoes de impressao no terminal

void Jogador::verMao() {
    for (int i = 0; i < mao.size(); ++i) {
        Carta* carta = mao[i];
        std::cout << "\t[" << i+1 << "] " << carta->getNome() << " " << carta->getTipo() <<  std::endl;
    }
    std::cout << std::endl;
}

void Jogador::verCampo() {
    for (int i = 0; i < campo.size(); ++i) {
        Carta* carta = campo[i];
        std::cout << "\t[" << i+1 << "] " << carta->getNome() << " " << carta->getTipo() <<  std::endl;
    }
}

void Jogador::descarta(const Carta* carta) {
    // seleciona uma carta da mão e descarta
    auto it = std::find_if(mao.begin(), mao.end(), [&](const Carta* c) { return *c == *carta; });
    if (it != mao.end()) {
        pilha_descarte.push_back(*it);
        mao.erase(it);
    }
}

void Jogador::declara_ataque(Unidade atacante, Unidade defensora){
    atacante.Atacar(defensora);
}

/*-------------------------------------------------------------------------*/
/*GETTERS E SETTERS*/

int Jogador::getcalor(){
    return qtdCalor;
}
void Jogador::setcalor(int _calor){
    qtdCalor = _calor;
}

int Jogador::getVida(){
    return vida;
}

std::string Jogador::getNome(){
    return nome;
}

std::vector<Carta*> Jogador::getMao(){
    return mao;
}
