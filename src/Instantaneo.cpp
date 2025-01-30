#include "../include/Instantaneo.h"
#include "../include/Jogador.h"
#include "../include/Unidade.h"

Instantaneo::Instantaneo(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID): Carta(_Desc, _Tipo, _Nome, _Custo, _ID), 
Tatica(_Desc, _Tipo, _Nome, _Custo, _ID){}

void Instantaneo::fornece_efeito(Jogador& jogador, Jogador& inimigo){
    switch(ID){
    case 21:

        for (auto carta : jogador.campo) {
            // Verifica se a carta é uma Unidade 
            if (auto unidadeCampo = dynamic_cast<Unidade*>(carta)) {
                unidadeCampo->receberDano(20);  // Aplica 20 de dano a cada unidade no campo do jogador
            }
        }

        for (auto carta : inimigo.campo) {
            // Verifica se a carta é uma Unidade
            if (auto unidadeCampo = dynamic_cast<Unidade*>(carta)) {
                unidadeCampo->receberDano(20);  // Aplica 20 de dano a cada unidade no campo do inimigo
            }
        }
    
    break;

    case 22:

        for (auto carta : jogador.mao) {
            carta->setCusto(carta->getCusto()-2);  // Diminui o custo em 2 - precisa ajustar para durar apenas 1 rodada
            if(carta->getCusto()<1)
                carta->setCusto(1);
        }
    
    break;

    case 23:  // aplicar metodo de destruir carta

        for (auto it = jogador.campo.begin(); it != jogador.campo.end(); ) {
            // Verifica se a carta é uma Unidade
            if (auto unidadeCampo = dynamic_cast<Unidade*>(*it)) {
                unidadeCampo->receberDano(unidadeCampo->getHp());  // Aplica o próprio número de vida como dano

                // Se a unidade foi destruída (HP == 0), remove ela do campo
                if (unidadeCampo->getHp() == 0) {
                    it = jogador.campo.erase(it);  // Remove a unidade e ajusta o iterador
                } else {
                    ++it;  // Se não foi destruída, apenas avança para o próximo elemento
                }
            } else {
                ++it;  // Se não for uma unidade, avança para o próximo elemento
            }
}

        for (auto it = inimigo.campo.begin(); it != inimigo.campo.end(); ) {
            // Verifica se a carta é uma Unidade
            if (auto unidadeCampo = dynamic_cast<Unidade*>(*it)) {
                unidadeCampo->receberDano(unidadeCampo->getHp());  // Aplica o próprio número de vida como dano

                // Se a unidade foi destruída (HP == 0), remove ela do campo
                if (unidadeCampo->getHp() == 0) {
                    it = inimigo.campo.erase(it);  // Remove a unidade e ajusta o iterador
                } else {
                    ++it;  // Se não foi destruída, apenas avança para o próximo elemento
                }
            } else {
                ++it;  // Se não for uma unidade, avança para o próximo elemento
            }
        }
    break;

        case 24:
        int unidadesDespachadas = 0;
        std::vector<Unidade*> unidadesCustoBaixo;

        // Coletar unidades com custo 2 ou menor
        for (auto carta : jogador.mao) {
            if (auto unidade = dynamic_cast<Unidade*>(carta)) {
                if (unidade->getCusto() <= 2) {
                    unidadesCustoBaixo.push_back(unidade);
                }
            }
        }

        // Verifica se há unidades de custo 2 ou menor disponíveis
        if (unidadesCustoBaixo.empty()) {
            std::cout << "Nenhuma unidade de custo 2 ou menor na mão!" << std::endl;
            return;
        }

        // Permitir ao jogador escolher até 2 unidades para despachar
        for (int i = 0; i < 2 && unidadesDespachadas < 2; ++i) {
            std::cout << "Escolha uma unidade para mover para o campo (Digite o número):" << std::endl;

            for (int j = 0; j < unidadesCustoBaixo.size(); ++j) {
                std::cout << j + 1 << ". " << unidadesCustoBaixo[j]->getNome() << " (Custo " << unidadesCustoBaixo[j]->getCusto() << ")" << std::endl;
            }

            int escolha;
            std::cin >> escolha;

            
            if (escolha >= 1 && escolha <= unidadesCustoBaixo.size()) {
                // Adiciona a unidade ao campo
                Carta* carta = unidadesCustoBaixo[escolha - 1];
                jogador.campo.push_back(carta);

                // Remove a unidade da mão
                for (size_t i = 0; i < jogador.mao.size(); i++) {
                    if (jogador.mao[i] == carta) {
                        jogador.mao.erase(jogador.mao.begin() + i);
                        break;  
                    }
                }

                // despachar para o campo
                unidadesDespachadas++;
                std::cout << unidadesCustoBaixo[escolha - 1]->getNome() << " foi movida para o campo!" << std::endl;
            } else {
                std::cout << "Escolha inválida, tente novamente." << std::endl;
            }
        }
    break;  


    }
}

