#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include "../include/Tatica.h"


class Equipamento : public Tatica{
    private:
        int atkextra;
        int hpextra;
        bool guarda;
        int calor_extra = 0; //calor extra gerado pelo equipamento, por padrão é 0
    public:
        void fornece_efeito(Unidade& unidade, Jogador& jogador) ;
        //construtores da classe Equipamento
        Equipamento(int atkextra, int hpextra, bool guarda, int _calor_extra, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
        Equipamento(int atkextra, int hpextra, bool guarda, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
        void leequipamento();
};

namespace EquipamentosPredefinidos{
    extern Equipamento GundamHammer;
    extern Equipamento ArmaduraChobam;
    extern Equipamento UpgradeGundam;
    extern Equipamento ReatorPartículasMinovsky;
}
#endif

