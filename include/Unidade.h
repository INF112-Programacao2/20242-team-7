#ifndef UNIDADE_H
#define UNIDADE_H

#include "../include/Carta.h"
#include <string>

class Piloto;

class Unidade : public Carta {
    private:
        std::string pilotoAssociado;
        int Atk, Hp; 
        bool Equip;         // Pilotado
        bool Guarda;
        int calor_produzido = 0; // Calor produzido pela unidade, por padrão é 0
        bool Evasao;
    public:
        Unidade();
        Unidade(int Atk, int Hp, int Custo, std::string Desc, std::string Tipo, std::string Nome, bool Equip, int ID, bool Guarda);
        Unidade(int Atk, int Hp, int Custo, std::string Desc, std::string Tipo, std::string Nome, bool Equip, int ID, bool Guarda, int calor_produzido);
        
        void Atacar(Unidade &Outra);
        void receberDano(int dano);
        bool isEquiped();
        void le();
        void ativa_guarda();
        void ativaEvasao();

        bool getEvasao();
        int getHp(); 
        void setHp(int _hp);
        int getAtk();
        void setAtk(int _atk);
        std::string getPiloto();
        void setPiloto(std::string nome_piloto);
        void setEquipavel(bool equip);
    };

namespace UnidadesPredefinidas {
    extern Unidade RX782Gundam;
    extern Unidade RX75Guntank;
    extern Unidade Guncannon;
    extern Unidade Ball;
    extern Unidade GM;
    extern Unidade Zeong;
    extern Unidade BigZam;
    extern Unidade Gelgoog;
    extern Unidade ZGok;
    extern Unidade Gouf;
    extern Unidade Zaku;
}
#endif