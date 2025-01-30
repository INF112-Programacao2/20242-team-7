#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include "Tatica.h"


class Equipamento : public Tatica{
    private:
        int atkextra;
        int hpextra;
        bool guarda;
    public:
        void fornece_efeito(Unidade unidade, Jogador jogador) override;
        Equipamento(int atkextra, int hpextra, bool guarda, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
};
#endif
