#include "../include/Carta.h"
#include "../include/Piloto.h"
#include "../include/Unidade.h"
#include "../include/Tatica.h"
#include "../include/Instantaneo.h"
#include "../include/Equipamento.h"
#include "../include/Partida.h"
#include "../include/Baralho.h"
#include "../include/Jogador.h"

#include <iostream>
#include <algorithm>
#include <random>

void iniciarMao(Jogador &jogador, Baralho &baralho, int qtd) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(baralho.cartas.begin(), baralho.cartas.end(), g);
    for (int i = 0; i < qtd && qtd <= baralho.quantidade_cartas(); ++i) {
        Carta* carta = baralho.seleciona_carta(i);
        jogador.compra_carta(carta);
    }
}

int main() {
    // Cria um baralho com algumas cartas
    Baralho baralho;
    //cabeçalho
    std::cout << 
    "| ----------------------------- Burning Steel Strife ---------------------------- \n" <<
    "| -------------------------------- Baralho criado ------------------------------- \n" <<
    "|                                                                                 \n" <<
    "| - Quantidade de cartas no baralho: " <<  baralho.quantidade_cartas()                << std::endl;


    // Cria dois jogadores com o baralho    
    std::string j1, j2;
    std::cout << "|\n| Digite o nome do Jogador 1: ";
    std::cin >> j1;
    std::cout << "|\n| Digite o nome do Jogador 2: ";
    std::cin >> j2;

    
    Jogador jogador1(20, j1, 0, {}, true);
    Jogador jogador2(20, j2, 0, {}, false);
    std::cout << "|\n| - Jogadores criados\n";

    std::cout << "|\n| - " << jogador1.getNome() << " x " << jogador2.getNome() << std::endl;

    int indice;

    // Jogador 1 compra 12 cartas do baralho, sendo 4 unidades, 2 equipamentos, 4 pilotos e 2 instantâneos
    iniciarMao(jogador1, baralho, 12);

    // Jogador 2 compra 12 cartas do baralho, sendo 4 unidades, 2 equipamentos, 4 pilotos e 2 instantâneos
    iniciarMao(jogador2, baralho, 12);

    // Cria uma partida com os dois jogadores
    Partida partida(jogador1.getNome(), jogador2.getNome());
    std::cout << "|\n| - " << "Partida iniciada\n";

    // Simula a partida
    while (!partida.encerra_partida(false)) {

        std::cout << "|\n| - " <<"Rodada: " << partida.rodada << std::endl;
        
        std::cout << "|\n| - " <<"Turno do " << (partida.getTurno() == 0 ? "Jogador 1" : "Jogador 2") << std::endl;
        if (partida.getTurno() == 0) {
            std::cout << "|\n| - " <<"Mao Jogador: " << jogador1.getNome() << std::endl;
            jogador1.verMao();

            std::cout << 
            "|\n| - 1 - Jogar Carta\n"
            "| - 2 - Atacar\n"
            "| - 3 - \n"
            "| - 4 - Encerrar Partida\n"
            "| - 5 - Exibir Historico\n"
            "| - 6 - Passar Turno\n"
            "| - 7 - Sair\n"
            "| » ";
            
            int opcao;
            std::cin >> opcao;

            Carta* carta = nullptr;
            Unidade* unidade = nullptr;
            Carta* cartainimigo = nullptr;
            Unidade* unidadeinimigo = nullptr;

            switch (opcao)
            {
            case 1:
                std::cout << "|\n| - " <<"Digite o numero da carta: ";
                std::cin >> indice;


                carta = jogador1.mao[indice-1];  // Obtém o objeto Carta
                // se a carta for uma unidade, ela é colocada no campo
                if (dynamic_cast<Unidade*>(carta)) {
                    jogador1.joga_carta(indice-1);
                    std::cout << "|\t - Carta jogada no campo: " << carta->getNome() << std::endl;
                }
                //se a carta for um piloto, ela é colocada em uma unidade
                else if (dynamic_cast<Piloto*>(carta)) {
                    int escolha;

                    std::cout << "|\n| - " <<"Pilotar\n| - Digite qual carta deseja pilotar"
                        "\n| - Para deixar piloto em campo, digite 0" << std::endl;
                    
                    jogador1.verCampo();
                    std::cout << "|\n » ";
                    std::cin>>escolha;

                    if(escolha == 0){
                        jogador1.joga_carta(indice-1);
                        std::cout << "|\t - Carta jogada no campo: " << carta->getNome() << std::endl;
                        break;
                    }else{
                        unidade = dynamic_cast<Unidade*>(jogador1.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                        if (unidade) {
                            Piloto* piloto = dynamic_cast<Piloto*>(carta);
                            unidade->setPiloto(piloto); // Associa o piloto à unidade
                            piloto->fornece_efeito(jogador1); // Aplica efeitos do piloto
                            jogador1.joga_carta(indice-1); // Move o piloto para o campo
                            std::cout << "|\t - " << piloto->getNome() << " pilotando " << unidade->getNome() << std::endl;
                        }
                    }
                }
                //se a carta for um equipamento, ela é equipada em uma unidade
                else if (dynamic_cast<Equipamento*>(carta)) {
                    int escolha;

                    std::cout << "|\n| - " <<"Equipar\n| - Digite a qual carta deseja fornecer equipamento";
                    jogador1.verCampo();
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador1.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    Equipamento* equipamento = dynamic_cast<Equipamento*>(carta);
                    unidade -> le();
                    equipamento->fornece_efeito(unidade, jogador1);
                    unidade->le();
                    std::cout << "|\t - Equipado com sucesso: " << carta->getNome() << std::endl;
                }

                else if (dynamic_cast<Instantaneo*>(carta)) {
                    int escolha;

                    std::cout << "|\n| - " <<"Fornecer efeito\n| - Digite qual carta deseja fornecer efeito";
                    jogador1.verCampo();
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador1.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    Instantaneo* instantaneo = dynamic_cast<Instantaneo*>(carta);
                    unidade -> le();
                    instantaneo->fornece_efeito(jogador1,jogador2);
                    unidade->le();
                    std::cout << "|\t - Efeito do instantâneo fornecido: " << carta->getNome() << std::endl;
                }
                
                else if (dynamic_cast<Tatica*>(carta)) {
                    int escolha;

                    std::cout << "|\n| - " <<"Fornecer efeito\n| - Digite qual carta deseja fornecer efeito";
                    jogador1.verCampo();
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador1.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    Tatica* tatica = dynamic_cast<Tatica*>(carta);
                    unidade -> le();
                    tatica->fornece_efeito(unidade, jogador1);
                    unidade->le();
                    std::cout << "|\t - Efeito da tática fornecido: " << carta->getNome() << std::endl;
                }

                break;
            case 2:

                std::cout << "|\n| - " <<"Atacar\n| - Digite qual carta deseja usar para atacar" << std::endl;
                jogador1.verCampo();
                int escolha;
                std::cin>>escolha;



                if (escolha < 1 || escolha > jogador1.campo.size()) {
                    std::cout << "|\n| - " <<"Escolha invalida! Selecione uma posicao valida." << " escolha : " << escolha << " posicao : " << jogador1.campo.size() << std::endl;
                    break;
                }

                 carta = jogador1.campo[escolha-1];  // Obtém o objeto Carta
            
                 if (carta == nullptr) {
                    std::cout << "|\n| - " <<"Nenhuma carta encontrada na posição escolhida!" << std::endl;
                    break;
                }

                
               
                 unidade = dynamic_cast<Unidade*>(carta);  // Tenta fazer o cast para Unidade

                if (unidade) {
                    // Se o cast foi bem-sucedido, você pode chamar métodos de Unidade
                    std::cout<<"Campo do inimigo :";
                    jogador2.verCampo();
                    std::cout<<"Escolha qual carta deseja atacar : ";
                    std::cin>>escolha;
                    std::cout<<std::endl;
                     cartainimigo = jogador2.campo[escolha-1];  // Obtém o objeto Carta inimigo
                     unidadeinimigo = dynamic_cast<Unidade*>(cartainimigo);  // Tenta fazer o cast para Unidade
                    if(unidadeinimigo){
                        std::cout<<"Atributos da carta selecionada para atacar : "<<std::endl;
                        unidade->le();
                        std::cout<<"Atributos da carta inimiga selecionada : "<<std::endl;
                        unidadeinimigo->le();
                        std::cout<<std::endl;
                        std::cout<<"HP Antes: "<<unidadeinimigo->getHp()<<std::endl;
                        unidade->Atacar(*unidadeinimigo);
                        std::cout<<"HP Depois: "<<unidadeinimigo->getHp()<<std::endl;
                    }    
                }
                else {
                    // Se o cast falhar, significa que a Carta não é do tipo Unidade
                    std::cout << "|\n| - " <<"A carta não é do tipo Unidade!" << std::endl;
                }

                break;
            //case 3:
             //   break;
            case 4:
                partida.encerra_partida(true);
                break;
            case 5:
            /*
                partida.exibe_historico();
            */
                break;
            case 6:
                partida.passa_turno();
                break;
            case 7:
                std::cout << "|\n| - " <<"Saindo\n";
                partida.encerra_partida(true);
                break;
            default:
                std::cout << "|\n| - " <<"Opcao invalida\n";
                break;
            }
        } else if (partida.getTurno() == 1) {

            Carta* carta = nullptr;
            Unidade* unidade = nullptr;
            Carta* cartainimigo = nullptr;
            Unidade* unidadeinimigo = nullptr;

            std::cout << "|\n| - " <<"Mao Jogador: " << jogador2.getNome() << std::endl;
            jogador2.verMao();
        
            std::cout << 
            "|\n| - 1 - Jogar Carta\n"
            "| - 2 - Atacar\n"
            "| - 3 - \n"
            "| - 4 - Encerrar Partida\n"
            "| - 5 - Exibir Historico\n"
            "| - 6 - Passar Turno\n"
            "| - 7 - Sair\n"
            "| » ";
            
            int opcao;
            std::cin >> opcao;

            switch (opcao)
            {
            case 1:
                std::cout << "|\n| - " <<"Digite o numero da carta: ";
                std::cin >> indice;
                //jogador1.joga_carta(indice-1); //duplicado
                jogador2.joga_carta(indice-1);
                break;
            case 2:

                std::cout << "|\n| - " <<"Atacar\n| - Digite qual carta deseja usar para atacar" << std::endl;
                jogador2.verCampo();
                int escolha;
                std::cin>>escolha;



                if (escolha < 1 || escolha > jogador2.campo.size()) {
                    std::cout << "|\n| - " <<"Escolha invalida! Selecione uma posicao valida." << " escolha : " << escolha << " posicao : " << jogador2.campo.size() << std::endl;
                    break;
                }

                 carta = jogador2.campo[escolha-1];  // Obtém o objeto Carta
            
                 if (carta == nullptr) {
                    std::cout << "|\n| - " <<"Nenhuma carta encontrada na posição escolhida!" << std::endl;
                    break;
                }

                
               
                 unidade = dynamic_cast<Unidade*>(carta);  // Tenta fazer o cast para Unidade

                if (unidade) {
                    // Se o cast foi bem-sucedido, você pode chamar métodos de Unidade
                    std::cout<<"Campo do inimigo :";
                    jogador1.verCampo();
                    std::cout<<"Escolha qual carta deseja atacar :";
                    std::cin>>escolha;
                    std::cout<<std::endl;
                     cartainimigo = jogador1.campo[escolha-1];  // Obtém o objeto Carta inimigo
                     unidadeinimigo = dynamic_cast<Unidade*>(cartainimigo);  // Tenta fazer o cast para Unidade
                    if(unidadeinimigo){
                        std::cout<<"Atributos da carta selecionada para atacar : "<<std::endl;
                        unidade->le();
                        std::cout<<"Atributos da carta inimiga selecionada : "<<std::endl;
                        unidadeinimigo->le();
                        std::cout<<std::endl;
                        std::cout<<"HP Antes: "<<unidadeinimigo->getHp()<<std::endl;
                        unidade->Atacar(*unidadeinimigo);
                        std::cout<<"HP Depois: "<<unidadeinimigo->getHp()<<std::endl;
                    }   
                } 
                else {
                    // Se o cast falhar, significa que a Carta não é do tipo Unidade
                    std::cout << "|\n| - " <<"A carta não é do tipo Unidade!" << std::endl;
                }
                
                break;
            //case 3:
            //    break;
            case 4:
                partida.encerra_partida(true);
                break;
            case 5:
            /*
                partida.exibe_historico();
            */
                break;
            case 6:
                partida.passa_turno();
                break;
            case 7:
                std::cout << "|\n| - " <<"Saindo\n";
                partida.encerra_partida(true);
                break;
            default:
                std::cout << "|\n| - " <<"Opcao invalida\n";
                break;
            }
        }

    }
/*
    // Exibe o histórico da partida
    partida.exibe_historico();
*/
    return 0;
}