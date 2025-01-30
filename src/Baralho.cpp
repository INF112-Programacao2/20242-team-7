#include "../include/Baralho.h"


using namespace UnidadesPredefinidas;
using namespace EquipamentosPredefinidos;
using namespace PilotosPredefinidos;
using namespace InstanteneoPredefinidos;

Carta* Baralho::seleciona_carta(int qtd) {
    if (qtd < cartas.size()) {
        return cartas[qtd];
    }
    return nullptr;
}

void Baralho::adiciona_carta(Carta* carta) {
    cartas.push_back(carta);
}

int Baralho::quantidade_cartas() {
    return cartas.size();
}

void Baralho::imprime_cartas() {
    for (Carta* carta : cartas) {
        carta->le();
        std::cout << std::endl;
    }
}

Baralho::Baralho() {
    inicializaBaralho(*this);
}

void Baralho::inicializaBaralho(Baralho& baralho) {
    // Adiciona unidades ao baralho
    baralho.adiciona_carta(new Unidade(RX782Gundam));
    baralho.adiciona_carta(new Unidade(RX75Guntank));
    baralho.adiciona_carta(new Unidade(Guncannon));
    baralho.adiciona_carta(new Unidade(Ball));
    baralho.adiciona_carta(new Unidade(GM));
    baralho.adiciona_carta(new Unidade(Zeong));
    baralho.adiciona_carta(new Unidade(BigZam));
    baralho.adiciona_carta(new Unidade(Gelgoog));
    baralho.adiciona_carta(new Unidade(ZGok));
    baralho.adiciona_carta(new Unidade(Gouf));
    baralho.adiciona_carta(new Unidade(Zaku));

    // Adiciona equipamentos ao baralho
    baralho.adiciona_carta(new Equipamento(GundamHammer));
    baralho.adiciona_carta(new Equipamento(ArmaduraChobam));
    baralho.adiciona_carta(new Equipamento(UpgradeGundam));
    baralho.adiciona_carta(new Equipamento(ReatorPartículasMinovsky));

    // Adiciona pilotos ao baralho
    baralho.adiciona_carta(new Piloto(AmuroRay));
    baralho.adiciona_carta(new Piloto(KayShiden));
    baralho.adiciona_carta(new Piloto(HayatoKobayashi));
    baralho.adiciona_carta(new Piloto(PilotoFederacao));
    baralho.adiciona_carta(new Piloto(CharAznable));
    baralho.adiciona_carta(new Piloto(DozleZabi));
    baralho.adiciona_carta(new Piloto(RambaRal));
    baralho.adiciona_carta(new Piloto(PilotoZeon));

    // Adiciona instantâneos ao baralho
    baralho.adiciona_carta(new Instantaneo(SistemaRaioSolar));
    baralho.adiciona_carta(new Instantaneo(ReforcosDaFederacao));
    baralho.adiciona_carta(new Instantaneo(OperacaoBritanica));
    baralho.adiciona_carta(new Instantaneo(NovaInvestida));
    baralho.adiciona_carta(new Instantaneo(INEUZaku));
    baralho.adiciona_carta(new Instantaneo(DesengajarCombate));
    baralho.adiciona_carta(new Instantaneo(CINADSN));
    baralho.adiciona_carta(new Instantaneo(ADCV));
}

Baralho::~Baralho() {
    // Libera a memória das cartas
    for (Carta* carta : cartas) {
        delete carta;
    }
}