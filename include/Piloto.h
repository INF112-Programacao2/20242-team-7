#ifndef PILOTO_H
#define PILOTO_H
#include "../include/Carta.h"
#include "../include/Jogador.h"
#include <cstring>

class Unidade;

class Piloto : public Carta{
private:
    std:: string efeito_piloto;
    Unidade unidade_tripulada;
public:
    Piloto(std::string _efeito_piloto, Unidade Unidade, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID );
    ~Piloto();
    void le();
    void fornece_efeito(Jogador& jog);
    void setUnidade(Unidade _unidade);
    Unidade getUnidade();
    
};

namespace PilotosPredefinidos{
    extern Piloto AmuroRay;
    extern Piloto KayShiden;
    extern Piloto HayatoKobayashi;
    extern Piloto PilotoFederacao;
    extern Piloto CharAznable;
    extern Piloto DozleZabi;
    extern Piloto RambaRal;
    extern Piloto PilotoZeon;
}


#endif