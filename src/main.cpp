#include "../include/Carta.h"
#include "../include/Piloto.h"
<<<<<<< Updated upstream
#include "../include/Unidade.h"
#include "../include/Tatica.h"
#include "../include/Instantaneo.h"
#include "../include/Equipamento.h"
#include "../include/Partida.h"
#include "../include/Baralho.h"
#include "../include/Jogador.h"
#include <iostream>

using namespace UnidadesPredefinidas;
using namespace EquipamentosPredefinidos;
using namespace PilotosPredefinidos;
using namespace InstanteneoPredefinidos;


void inicializaBaralho(Baralho& baralho) {
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

int main() {
    // Cria um baralho com algumas cartas
    Baralho baralho;
    inicializaBaralho(baralho);
    //cabeçalho
    std::cout << 
    "| ----------------------------- Burning Steel Strife ---------------------------- |\n" <<
    "| -------------------------------- Baralho criado-------------------------------- |\n" <<
    "|                                                                                 |\n" <<
    "| - Quantidade de cartas no baralho: " << baralho.quantidade_cartas()                    <<
    " ----------------------------------------- |"<< std::endl;


    // Cria dois jogadores com o baralho    
    std::string j1, j2;
    std::cout << "Digite o nome do Jogador 1: ";
    std::cin >> j1;
    std::cout << "Digite o nome do Jogador 2: ";
    std::cin >> j2;

    
    Jogador jogador1(20, j1, 0, {}, true);
    Jogador jogador2(20, j2, 0, {}, false);
    std::cout << "Jogadores criados\n";

    std::cout << jogador1.getNome() << " x " << jogador2.getNome() << std::endl;

    int indice;

    for (int i = 0; i < 10 ; i++) {
        jogador1.compra_carta(i);
        //imprime a carta comprada
    }
    for (int j = 10; j < 20; j++) {
        jogador2.compra_carta(j);
    }

    // Cria uma partida com os dois jogadores
    Partida partida(jogador1.getNome(), jogador2.getNome());
    std::cout << "Partida iniciada\n";

    // Simula a partida
    while (!partida.encerra_partida(false)) {

        std::cout << "Rodada: " << partida.rodada << std::endl;
        
        std::cout << "Turno do " << (partida.getTurno() == 0 ? "Jogador 1" : "Jogador 2") << std::endl;
        if (partida.getTurno() == 0) {
            std::cout << "Mao Jogador: " << jogador1.getNome() << std::endl;
            jogador1.verMao();

            std::cout << "1 - Jogar Carta\n2 - Atacar\n3 - \n4 - Encerrar Partida\n5 - Exibir Historico\n6 - Passar Turno\n7 - Sair\n";
            int opcao;
            std::cin >> opcao;

            switch (opcao)
            {
            case 1:
                std::cout << "Digite o numero da carta: ";
                std::cin >> indice;

                jogador1.joga_carta(indice-1);
                break;
            case 2:
                std::cout << "Atacar\n";
                break;
            case 3:
                break;
            case 4:
                partida.encerra_partida(true);
                break;
            case 5:
                partida.exibe_historico();
                break;
            case 6:
                partida.passa_turno();
                break;
            case 7:
                std::cout << "Saindo\n";
                partida.encerra_partida(true);
                break;
            default:
                std::cout << "Opcao invalida\n";
                break;
            }
        } else if (partida.getTurno() == 1) {
            std::cout << "Mao Jogador: " << jogador2.getNome() << std::endl;
            jogador2.verMao();
        
            std::cout << "1 - Jogar Carta\n2 - Atacar\n3 - \n4 - Encerrar Partida\n5 - Exibir Historico\n6 - Passar Turno\n7 - Sair\n";
            int opcao;
            std::cin >> opcao;

            switch (opcao)
            {
            case 1:
                std::cout << "Digite o numero da carta: ";
                std::cin >> indice;
                jogador1.joga_carta(indice-1);
                jogador2.joga_carta(0);
                break;
            case 2:
                std::cout << "Atacar\n";
                break;
            case 3:
                break;
            case 4:
                partida.encerra_partida(true);
                break;
            case 5:
                partida.exibe_historico();
                break;
            case 6:
                partida.passa_turno();
                break;
            case 7:
                std::cout << "Saindo\n";
                partida.encerra_partida(true);
                break;
            default:
                std::cout << "Opcao invalida\n";
                break;
            }
        }

        // Passa o turno
        partida.passa_turno();
    }

    // Exibe o histórico da partida
    partida.exibe_historico();

    return 0;
=======
#include "../include/Baralho.h"
#include <iostream>
#include <vector>

int main() {
    try {
        std::cout << "Iniciando o jogo...\n";
        
        // Criar baralhos iniciais
        Baralho baralho1;
        Baralho baralho2;
        std::cout << "Baralhos criados\n";

        // Criar cópias das cartas predefinidas
        Unidade* gundam = new Unidade(UnidadesPredefinidas::RX782Gundam);
        Unidade* guncannon = new Unidade(UnidadesPredefinidas::Guncannon);
        Unidade* gm = new Unidade(UnidadesPredefinidas::GM);
        
        Unidade* bigzam = new Unidade(UnidadesPredefinidas::BigZam);
        Unidade* gouf = new Unidade(UnidadesPredefinidas::Gouf);
        Unidade* zaku = new Unidade(UnidadesPredefinidas::Zaku);

        // Adicionar cartas aos baralhos
        baralho1.adiciona_carta(gundam);
        baralho1.adiciona_carta(guncannon);
        baralho1.adiciona_carta(gm);
        
        baralho2.adiciona_carta(bigzam);
        baralho2.adiciona_carta(gouf);
        baralho2.adiciona_carta(zaku);
        
        std::cout << "Cartas adicionadas aos baralhos\n";

        // Receber nomes dos jogadores
        std::string nome1, nome2;
        std::cout << "Nome do Jogador 1: ";
        std::getline(std::cin, nome1);
        std::cout << "Nome do Jogador 2: ";
        std::getline(std::cin, nome2);
        
        std::cout << "Criando jogadores...\n";

        // Criar jogadores (vida 100, calor inicial 20)
        Jogador jogador1(100, nome1, 20, baralho1, true);
        Jogador jogador2(100, nome2, 20, baralho2, false);
        
        std::cout << "Jogadores criados com sucesso\n";

        // Criar partida
        std::cout << "Iniciando partida...\n";
        Partida partida(nome1, nome2, false, 0, 0, "", 0);
        
        std::cout << "Partida criada com sucesso\n";

        // Dar cartas iniciais
        std::cout << "Distribuindo cartas iniciais...\n";
        for(int i = 0; i < 3 && i < baralho1.quantidade_cartas(); i++) {
            std::cout << "Tentando comprar carta " << i + 1 << " para jogador 1\n";
            jogador1.compra_carta(i);
        }
        for(int i = 0; i < 3 && i < baralho2.quantidade_cartas(); i++) {
            std::cout << "Tentando comprar carta " << i + 1 << " para jogador 2\n";
            jogador2.compra_carta(i);
        }

        std::cout << "\nIniciando loop principal do jogo...\n";

        // Loop principal do jogo
        while(!partida.encerra_partida()) {
            Jogador& jogador_atual = partida.getTurno() == 0 ? jogador1 : jogador2;
            Jogador& jogador_inimigo = partida.getTurno() == 0 ? jogador2 : jogador1;

            std::cout << "\n=== Turno de " << jogador_atual.getNome() << " ===\n";
            std::cout << "Vida: " << jogador_atual.getVida() << " | Calor: " << jogador_atual.getcalor() << "\n";
            std::cout << "Inimigo - Vida: " << jogador_inimigo.getVida() << "\n\n";

            std::cout << "Sua mão:\n";
            jogador_atual.verMao();

            std::cout << "\nSeu campo:\n";
            for(const auto& carta : jogador_atual.getCampo()) {
                if(auto unidade = dynamic_cast<Unidade*>(carta)) {
                    std::cout << unidade->getNome() << " (ATK:" << unidade->getAtk() 
                             << " HP:" << unidade->getHp() << ")\n";
                }
            }

            std::cout << "\nAções disponíveis:\n";
            std::cout << "1. Jogar carta\n";
            std::cout << "2. Atacar\n";
            std::cout << "3. Passar turno\n";
            std::cout << "4. Encerrar jogo\n";
            std::cout << "Escolha uma ação: ";
            
            int escolha;
            std::cin >> escolha;
            std::cin.ignore(); // Limpar o buffer

            switch(escolha) {
                case 1: {
                    if(jogador_atual.mao.empty()) {
                        std::cout << "Sem cartas na mão!\n";
                        break;
                    }
                    
                    std::cout << "Escolha a carta para jogar (0-" << jogador_atual.mao.size()-1 << "): ";
                    int index;
                    std::cin >> index;
                    std::cin.ignore();
                    
                    if(index >= 0 && index < jogador_atual.mao.size()) {
                        jogador_atual.joga_carta(index);
                        std::cout << "Carta jogada com sucesso!\n";
                    }
                    break;
                }
                // ... resto do código do switch permanece o mesmo ...
                
                case 4:
                    std::cout << "Encerrando partida...\n";
                    partida.encerra_partida(true);
                    break;
                default:
                    std::cout << "Opção inválida!\n";
            }

            if(jogador1.getVida() <= 0) {
                std::cout << "\n" << jogador2.getNome() << " venceu!\n";
                break;
            } else if(jogador2.getVida() <= 0) {
                std::cout << "\n" << jogador1.getNome() << " venceu!\n";
                break;
            }
        }

        std::cout << "Jogo encerrado!\n";
        return 0;

    } catch (const std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cout << "Erro desconhecido ocorreu!" << std::endl;
        return 1;
    }
>>>>>>> Stashed changes
}