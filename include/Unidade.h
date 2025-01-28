#ifndef UNIDADE_H
#define UNIDADE_H

#include "../include/Carta.h"
#include <string>

class Unidade : public Carta {
    private:
        int Atk, Def, Hp; 
        bool Equip;         // Pilotado
        bool Guarda;
        int calor_produzido = 0; // Calor produzido pela unidade, por padrão é 0
        bool Evasao;
    public:
        int getHp(); 
        void setHp(int _hp);
        int getAtk();
        void setAtk(int _atk);
        int getDef();
        Unidade();
        Unidade(int Atk, int Def, int Hp, int Custo, std::string Desc, std::string Tipo, std::string Nome, bool Equip, int ID, bool Guarda);
        Unidade(int Atk, int Def, int Hp, int Custo, std::string Desc, std::string Tipo, std::string Nome, bool Equip, int ID, bool Guarda, int calor_produzido);
        void Atacar(Unidade &Outra);
        void receberDano(int dano);
        bool isEquiped();
        void recebe_efeito();
        void le()const;
        void ativa_guarda();
        bool getEvasao();
        void ativaEvasao();
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