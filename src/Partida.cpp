#define VIDA_INICIAL 100
#define CALOR_INICIAL 20

#include "../include/Partida.h"


Partida::Partida()
    :   j1(VIDA_INICIAL, "Jogador 1", CALOR_INICIAL, {}, true), j2(VIDA_INICIAL, "Jogador 2", CALOR_INICIAL, {}, false) {
    tempo = 0;
    rodada = 0;
    historico = "";
    turno = 0;
}
Partida::Partida(std::string nome_j1, std::string nome_j2)
    :  j1(VIDA_INICIAL, nome_j1, CALOR_INICIAL, {}, true), j2(VIDA_INICIAL, nome_j2, CALOR_INICIAL, {}, false) {
    tempo = 0;
    rodada = 0;
    historico = "";
    turno = 0;
}

bool Partida::encerra_partida(bool _fim) {
    if (_fim) {
        std::cout << "Partida encerrada!" << std::endl;
        fim  = _fim;
        return true;
    } else
        if (j1.getVida() <= 0 || j1.getVida() < j2.getVida() && fim) {
            std::cout << "Jogador " << j2.getNome() << " venceu a partida!" << std::endl;
            return true;
        } else if (j2.getVida() <= 0 || j2.getVida() < j1.getVida() && fim) {
            std::cout << "Jogador " << j1.getNome() << " venceu a partida!" << std::endl;
            return true;
        } else if (j1.getVida() == j2.getVida() && fim) {
            std::cout << "Empate!!!" << std::endl;
            return true;
        }
        return false;
}

/*void Partida::exibe_historico() {
    std::cout << "Histórico da partida: " << historico << std::endl;
}
*/

void Partida::passa_turno() {
    // Troca o turno
    // 0 -> Jogador 1
    // 1 -> Jogador 2
    turno = (turno + 1) % 2;
}

int Partida::getTurno() {
    return turno;
}

