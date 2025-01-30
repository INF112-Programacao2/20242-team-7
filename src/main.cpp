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

void iniciarMao(Jogador& jogador, Baralho& baralho) {
    // Embaralha o baralho
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(baralho.cartas.begin(), baralho.cartas.end(), g);



    int unidades = 0, equipamentos = 0, pilotos = 0, instantaneos = 0;
    for (Carta* carta : baralho.cartas) {
        if (unidades < 4 && dynamic_cast<Unidade*>(carta)) {
            jogador.compra_carta(carta);
            unidades++;
        } else if (equipamentos < 2 && dynamic_cast<Equipamento*>(carta)) {
            jogador.compra_carta(carta);
            equipamentos++;
        } else if (pilotos < 4 && dynamic_cast<Piloto*>(carta)) {
            jogador.compra_carta(carta);
            pilotos++;
        } else if (instantaneos < 2 && dynamic_cast<Instantaneo*>(carta)) {
            jogador.compra_carta(carta);
            instantaneos++;
        }
        if (jogador.getMao().size() == 12) break;
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

    //Ambos os jogadpres são criados com 20 de calor e uma mão vazia.
    //O jogador 1 começa o jogo, o primeiro turno é dele, por isso recebe +5 de calor.
    Jogador jogador1(20, j1, 25, {}, true);
    Jogador jogador2(20, j2, 25, {}, false);
    std::cout << "|\n| - Jogadores criados\n";

    std::cout << "|\n| - " << jogador1.getNome() << " x " << jogador2.getNome() << std::endl;

    int indice;

    // Jogador 1 compra 12 cartas do baralho, sendo 4 unidades, 2 equipamentos, 4 pilotos e 2 instantâneos
    iniciarMao(jogador1, baralho);

    // Jogador 2 compra 12 cartas do baralho, sendo 4 unidades, 2 equipamentos, 4 pilotos e 2 instantâneos
    iniciarMao(jogador2, baralho);

    // Cria uma partida com os dois jogadores
    Partida partida(jogador1.getNome(), jogador2.getNome());
    std::cout << "|\n| - " << "Partida iniciada\n";

    // Simula a partida
    while (!partida.encerra_partida(false)) {

        std::cout << "|\n| - " <<"Rodada: " << partida.rodada << std::endl;
        
        std::cout << "|\n| - " <<"Turno do " << (partida.getTurno() == 0 ? "Jogador 1" : "Jogador 2") << std::endl;
        //turno do jogador 1
        if (partida.getTurno() == 0) {
            std::cout << "|\n| - " <<"Mao Jogador: " << jogador1.getNome() << std::endl;
            jogador1.verMao();

            std::cout<< "|\n| -Calor:" << jogador1.getcalor()<<std::endl;

            std::cout << 
            "|\n| - 1 - Jogar Carta\n"
            "| - 2 - Atacar\n"
            "| - 3 - Ver cartas baralho\n"
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
            Equipamento* equipamento = nullptr;

            switch (opcao)
            {
            //Jogar carta
            case 1:
                std::cout << "|\n| - " <<"Digite o numero da carta: ";
                std::cin >> indice;

                carta = jogador1.mao[indice-1];  // Obtém o objeto Carta
                if(jogador1.getcalor()<carta->getCusto()){
                    std::cout<<"Voce nao possui calor suficiente para lançar essa carta" <<std::endl;
                    break;
                }
                else{
                // se a carta for uma unidade, ela é colocada no campo
                if (dynamic_cast<Unidade*>(carta)) {
                    jogador1.joga_carta(indice-1); //Joga a carta
                    carta->gasta_calor(carta->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                    
                    std::cout << "|\t - Carta jogada no campo: " << carta->getNome() << std::endl;
                }
                //se a carta for um piloto, ela é colocada em uma unidade
                else if (dynamic_cast<Piloto*>(carta)) {

                    std::cout << "|\n| - " <<"Pilotar\n| - Digite qual carta deseja pilotar"
                        "\n| - Para deixar piloto em campo, digite 0" << std::endl;
                    
                    jogador1.verCampo();
                    std::cout << "|\n » ";
                    int escolha;
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador1.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    Piloto* piloto = dynamic_cast<Piloto*>(carta);
                    unidade->setPiloto(piloto->getNome()); //Coloca o piloto na unidade
                    piloto -> setUnidade(*unidade); //Atribui a unidade ao piloto
                    std::cout << "|\t - Piloto associado a unidade: " << piloto -> getNome() << std::endl;

                    piloto -> fornece_efeito(jogador1);

                    std::cout << "|\t - Pilotado com sucesso: " << piloto -> getNome() << std::endl;
                    unidade -> le();
                    carta->gasta_calor(carta->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                    
                }
                //se a carta for um equipamento, ela é equipada em uma unidade
                else if (dynamic_cast<Equipamento*>(carta)) {
                    int escolha;
                    std::cout << "|\n| - " <<"Equipar\n| - Digite a qual carta deseja fornecer equipamento";
                    jogador1.verCampo();
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador1.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    equipamento = dynamic_cast<Equipamento*>(carta);
                    equipamento->fornece_efeito(*unidade, jogador1);
                    unidade->le();
                    std::cout << "|\t - Equipado com sucesso: " << carta->getNome() << std::endl;
                    carta->gasta_calor(carta->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                }
                // se a carta for um instantâneo, ela é usada imediatamente
                else if (dynamic_cast<Instantaneo*>(carta)) {
                    int escolha;

                    std::cout << "|\n| - " <<"Fornecer efeito\n| - Digite qual carta deseja fornecer efeito";
                    jogador1.verCampo();
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador1.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    Instantaneo* instantaneo = dynamic_cast<Instantaneo*>(carta);
                    
                    instantaneo->fornece_efeito(jogador1,jogador2);
                    unidade->le();
                    std::cout << "|\t - Efeito do instantâneo fornecido: " << carta->getNome() << std::endl;
                    carta->gasta_calor(carta->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                }
                
                else if (dynamic_cast<Tatica*>(carta)) {
                    int escolha;

                    std::cout << "|\n| - " <<"Fornecer efeito\n| - Digite qual carta deseja fornecer efeito";
                    jogador1.verCampo();
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador1.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    Tatica* tatica = dynamic_cast<Tatica*>(carta);
                    
                    tatica->fornece_efeito(*unidade, jogador1);
                    unidade->le();
                    std::cout << "|\t - Efeito da tática fornecido: " << carta->getNome() << std::endl;
                    carta->gasta_calor(carta->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                }

                break;
                }
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
                    if (jogador2.campo.empty()) {
                        std::cout << "Deseja atacar diretamente o jogador inimigo? (s/n) ";
                        char resposta;
                        std::cin >> resposta;
                        if (resposta == 's') {
                            jogador2.setvida(jogador2.getVida() - unidade->getAtk());
                            std::cout << "|\n| - " <<"Ataque realizado com sucesso!" << std::endl;
                            std::cout<<"Vida do jogador inimigo após o ataque : "<<jogador2.getVida()<<std::endl;
                            partida.passa_turno();
                            std::cout<<"|\n| - rodada do jogador 2!"<<std::endl;
                            
                            break;
                        }
                        break;
                    }
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
                jogador1.setcalor(jogador1.getcalor()+5);//No início de cada turno, os jogadores recebem +5 de calor
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
            Equipamento* equipamento = nullptr;

            std::cout << "|\n| - " <<"Mao Jogador: " << jogador2.getNome() << std::endl;
            jogador2.verMao();
            std::cout<< "|\n| -Calor:" << jogador2.getcalor()<<std::endl;
        
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

                carta = jogador2.mao[indice-1];  // Obtém o objeto Carta
                if(jogador2.getcalor()<carta->getCusto()){
                    std::cout<<"Voce nao possui calor suficiente para lançar essa carta" <<std::endl;
                    break;
                }
                else{
            
                if (dynamic_cast<Unidade*>(carta)) { //A carta é uma unidade??
                    jogador2.joga_carta(indice-1); //Joga a carta
                    carta->gasta_calor(carta->getCusto(), jogador2);//Debita o custo da carta do calor do jogador
                    
                    std::cout << "|\t - Carta jogada no campo: " << carta->getNome() << std::endl;
                }


                else if (dynamic_cast<Piloto*>(carta)) { //A carta é um piloto??
                    int escolha;

                    std::cout << "|\n| - " <<"Pilotar\n| - Digite qual carta deseja pilotar"
                        "\n| - Para deixar piloto em campo, digite 0" << std::endl;
                    
                    jogador2.verCampo(); //Apresenta o campo para o jogador decidir
                    std::cout << "|\n » ";
                    std::cin>>escolha;

                    if(escolha == 0){
                        jogador2.joga_carta(indice-1);
                        std::cout << "|\t - Carta jogada no campo: " << carta->getNome() << std::endl;
                        carta->gasta_calor(carta->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                        break;
                    }else{
                        unidade = dynamic_cast<Unidade*>(jogador2.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                        Piloto* piloto = dynamic_cast<Piloto*>(carta);
                        unidade->setPiloto(piloto->getNome());
                        std::cout << "|\t - Pilotado com sucesso: " << piloto -> getNome() << std::endl;
                        
                        piloto->gasta_calor(piloto->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                    }
                }

                 //se a carta for um equipamento, ela é equipada em uma unidade
                else if (dynamic_cast<Equipamento*>(carta)) {
                    int escolha;
                    std::cout << "|\n| - " <<"Equipar\n| - Digite a qual carta deseja fornecer equipamento";
                    jogador2.verCampo();
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador2.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    equipamento = dynamic_cast<Equipamento*>(carta);
                    equipamento->fornece_efeito(*unidade, jogador2);
                    unidade->le();
                    std::cout << "|\t - Equipado com sucesso: " << carta->getNome() << std::endl;
                    carta->gasta_calor(carta->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                }

                 else if (dynamic_cast<Instantaneo*>(carta)) { //A carta é um efeito insantaneo??
                    int escolha;

                    std::cout << "|\n| - " <<"Fornecer efeito\n| - Digite qual carta deseja fornecer efeito";
                    jogador2.verCampo();
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador2.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    Instantaneo* instantaneo = dynamic_cast<Instantaneo*>(carta);
                    
                    instantaneo->fornece_efeito(jogador2,jogador1);
                    unidade->le();
                    std::cout << "|\t - Efeito do instantâneo fornecido: " << carta->getNome() << std::endl;
                    carta->gasta_calor(carta->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                }
                
                else if (dynamic_cast<Tatica*>(carta)) { //A carta é uma tática??
                    int escolha;

                    std::cout << "|\n| - " <<"Fornecer efeito\n| - Digite qual carta deseja fornecer efeito";
                    jogador2.verCampo();
                    std::cin>>escolha;

                    unidade = dynamic_cast<Unidade*>(jogador2.campo[escolha-1]);  // Tenta fazer o cast para Unidade
                    Tatica* tatica = dynamic_cast<Tatica*>(carta);
                    
                    tatica->fornece_efeito(*unidade, jogador2);
                    unidade->le();
                    std::cout << "|\t - Efeito da tática fornecido: " << carta->getNome() << std::endl;
                    carta->gasta_calor(carta->getCusto(), jogador1);//Debita o custo da carta do calor do jogador
                }



                break;
                }
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
                    if (jogador1.campo.empty()) {
                        std::cout << "Deseja atacar diretamente o jogador inimigo? (s/n) ";
                        char resposta;
                        std::cin >> resposta;
                        if (resposta == 's') {
                            jogador1.setvida(jogador1.getVida() - unidade->getAtk());
                            std::cout << "|\n| - " <<"Ataque realizado com sucesso!" << std::endl;
                            std::cout<<"Vida do jogador inimigo após o ataque : "<<jogador1.getVida()<<std::endl;
                            partida.passa_turno();
                            std::cout<<"|\n| - rodada do jogador 1!"<<std::endl;
                            jogador2.setcalor(jogador2.getcalor()+5); // No início de cada turno, os jogadores recebem +5 de calor
                            break;
                        }
                        break;
                    }
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
                jogador2.setcalor(jogador2.getcalor()+5);
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