#ifndef UNIDADE_H
#define UNIDADE_H

#include "Carta.h"

class Unidade : public Carta {
    private:
        int Atk, Def, Hp; 
        bool Equip;         // Pilotado
        bool Guarda;
    public:
        int getHp(); 
        void setHp(int _hp);
        int getAtk();
        void setAtk(int _atk);
        int getDef();
        Unidade(int Atk, int Def, int Hp, int Custo, std::string Desc, std::string Tipo, std::string Nome, bool Equip, int ID, bool Guarda);
        void Atacar(Unidade &Outra);
        void receberDano(int dano);
        bool isEquiped();
        void recebe_efeito();
        void le()const;
        void ativa_guarda();
    };

namespace UnidadesPredefinidas {
    extern const Unidade RX782Gundam;
    extern const Unidade RX75Guntank;
    extern const Unidade Guncannon;
    extern const Unidade Ball;
    extern const Unidade GM;
    extern const Unidade Zeong;
    extern const Unidade BigZam;
    extern const Unidade Gelgoog;
    extern const Unidade ZGok;
    extern const Unidade Gouf;
    extern const Unidade Zaku;
}
#endif