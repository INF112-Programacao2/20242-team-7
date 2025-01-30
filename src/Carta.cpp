#include "../include/Carta.h"
#include "../include/Jogador.h"
#include <iomanip>

//Métodos de acesso:
int Carta::getID() {
    return ID; //Retorna o ID
}

int Carta::getCusto() {
    return Custo; //Retorna
}

std::string Carta::getTipo() {
    return Tipo; //Retorna o tipo da carta
}

std::string Carta::getNome(){
    return Nome; //Retorna o nome
}

std::string Carta::getDesc(){
    return Descricao; //Retorna a descrição
}

void Carta::le() {
    std::cout << "| \t* Nome: " << Nome << std::endl; //Imprime o nome
    std::cout << "| \t* Tipo: " << Tipo << std::endl; //Imprime o tipo
    std::cout << "| \t* Custo: " << Custo << std::endl; //Imprime o custo
    std::cout << "| \t* Descricao: " << Descricao << std::endl; //Imprime a descrição
}

void Carta::infoBasica(){
    std::cout << "\t* Nome: " << std::setw(20) << std::left << Nome 
              << "\t* Tipo: " << std::setw(15) << std::left << Tipo 
              << "\t* Custo: " << Custo << std::endl;
}

void Carta::setEquipavel(bool equip){
    equipavel = equip; //Seta o valor de equipavel
}

bool Carta::getEquipavel(){
    return equipavel; 
}

//Construtor:
Carta::Carta(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
    : Descricao(_Desc), Tipo(_Tipo), Nome(_Nome), Custo(_Custo), ID(_ID) {}

Carta::Carta(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID, bool _Equip)
    : Descricao(_Desc), Tipo(_Tipo), Nome(_Nome), Custo(_Custo), ID(_ID), equipavel(_Equip) {}

//Destrutor:
Carta::~Carta() {} 

void Carta::gasta_calor(int custo, Jogador& jogador){ //Gasta calor
    jogador.setcalor(jogador.getcalor() - custo); // seta o valor de calor no valor da quantidade atual
                                                  // possuída pelo jogador, menos o custo da carta
}
void Carta::gera_calor(int qtd, Jogador& jogador){
    jogador.setcalor(jogador.getcalor() + qtd); //Seta calor com a quanidade anterior + o que foi gerado.
                                                // É usada no efeitos especiais de algumas das cartas
}

 void Carta::fornece_efeito(){} //Específico pra cada carta, implementado nas subclasses

void Carta::setCusto(int custo){ //Custo
    Custo = custo;
}

bool Carta::operator==(const Carta& other) const {
        // Implementação da comparação
        return this->ID == other.ID; //Compara o ID da carta
    }

