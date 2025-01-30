#ifndef JOGADOR_H
#define JOGADOR_H
#include <vector>
#include <string>
#include "Carta.h"
#include "Baralho.h"
#include "Unidade.h"

class Jogador{
    protected:
        int vida; 
        std::string nome;
        std::vector<Carta> mao;
        int qtdCalor;
        Baralho baralho;
        std::vector<Carta> pilhaDescarte;
        std::vector<Carta> campo;
        bool vezDeJogar;
     
    public:    
        void declara_ataque(Unidade atacante, Unidade defensora);
        int getcalor();
        void setcalor(int _calor);


      
    
};
#endif