#ifndef PILOTO_H
#define PILOTO_H
#include "Carta.h"
#include "Unidade.h"
#include "Jogador.h"
#include <cstring>

class Piloto : public Carta{
    private:
    std:: string efeito_piloto;
    Unidade unidade_tripulada;
    public:
    Piloto(std::string _efeito_piloto, Unidade Unidade, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID );
    ~Piloto();
    void fornece_efeito(Jogador& jog);
<<<<<<< Updated upstream
    Unidade getUnidade();
=======
>>>>>>> Stashed changes
    
};

namespace PilotosPredefinidos{
    extern const Piloto AmuroRay;
    extern const Piloto KayShiden;
    extern const Piloto HayatoKobayashi;
    extern const Piloto PilotoFederacao;
    extern const Piloto CharAznable;
    extern const Piloto DozleZabi;
    extern const Piloto RambaRal;
    extern const Piloto PilotoZeon;
}


#endif