#ifndef INSTANTANEO_H
#define INSTANTANEO_H

#include "../include/Tatica.h"
class Jogador;
class Unidade;

class Instantaneo : public Tatica{
    public:
        void fornece_efeito (Jogador jogador, Jogador inimigo);
        // Construtor padrão
        Instantaneo(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
};

namespace InstanteneoPredefinidos{
    extern Instantaneo SistemaRaioSolar;
    extern Instantaneo OperacaoBritanica;
    extern Instantaneo ReforcosDaFederacao;
    extern Instantaneo NovaInvestida;
    extern Instantaneo INEUZaku;
    extern Instantaneo DesengajarCombate;
    extern Instantaneo CINADSN;
    extern Instantaneo ADCV;
}
#endif