   #include "../include/Piloto.h"
   #include "../include/Carta.h"
   #include "../include/Jogador.h"
   #include <iostream>
   #include <exception>
   #include <stdexcept>
   
   
   

Piloto :: Piloto(std::string _efeito_piloto, Unidade _unidade_tripulada, std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID)
    :Carta(_Desc, _Tipo, _Nome, _Custo, _ID),//Chama o construtor da superclasse
    unidade_tripulada(_unidade_tripulada),//Unidade do piloto
    efeito_piloto(_efeito_piloto){ //Efeito do piloto
    }

Piloto::~Piloto(){}//Nada no destrutor, sem alocação dinâmica

/*ACOES*/

void Piloto::fornece_efeito(Jogador& jog) {
    Jogador jogador = jog;
    int decide = 0;
    int nPF = 0; // Contagem de pilotos da federação em campo
    std::vector<int> indicesF; // Lista que vai guardar os índices de cartas em campo que são pilotos genéricos da federação
    int contH = 0; // Inicia a contagem de Heróis
    std::vector<int> indicesP; // Lista que vai guardar os índices dos peões
    int nPZ=0;
    std::vector<int> indicesZ; // Lista que vai guardar os índices dos peões


    switch (ID) {
        case 1: // Amuro Ray
            unidade_tripulada.setHp(unidade_tripulada.getHp() + 25);
            if (unidade_tripulada.getNome() == "RX78-2 GUNDAM") {
                unidade_tripulada.ativaEvasao();
            }
            break;

        case 2: // Kay Shiden
            if (unidade_tripulada.getTipo() == "Heroi") {
                unidade_tripulada.setAtk(unidade_tripulada.getAtk() + 30);
            }
            break;

        case 3: // Hayato
            try {
                std::cout << "|\t - Deseja gastar 2 pontos de calor e converter a unidade pilotada por Hayato Kobayashi em uma RX-75 GUNTANK?" << std::endl;
                std::cout << "|\t - 0 - Não" << std::endl;
                std::cout << "|\t - 1 - Sim" << std::endl;

                std::cin >> decide;
                if (std::cin.fail()) {
                    throw std::runtime_error("Entrada inválida. Por favor, insira um número inteiro!");
                } else if (decide == 0) {
                    break;
                } else if (decide == 1) {
                    if(jog.getcalor()<2){
                        std::cout << "|\t - Voce nao possui calor suficiente para essa acao"<<std::endl;
                    }
                    else{
                        jog.setcalor(jog.getcalor()-2); //Gasta 2 calor
                        unidade_tripulada = UnidadesPredefinidas::RX75Guntank; //Transforma a unidade em RX75
                    }
                } else {
                    throw std::out_of_range("Opção inválida. Por favor, escolha 0 ou 1.");
                }
            } catch (const std::exception& e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
            break;

        case 4: // Genérico federação
            // Percorre Campo
            for (int i = 0; i < jog.campo.size(); i++) {
                Piloto* piloto = dynamic_cast<Piloto*>(jog.campo[i]);
                if (piloto && piloto->getNome() == "Piloto da Federacao") { // Verifica se é um genérico da federação
                    nPF++; // Se sim, contabiliza em nPF
                    indicesF.push_back(i); // Guarda o índice
                }
            }

            if (nPF >= 2) { // Se nPF é maior ou igual a 2
                for (int i = 0; i < indicesF.size(); i++) { // Percorre índices
                    Piloto* piloto = dynamic_cast<Piloto*>(jog.campo[indicesF[i]]);
                    if (piloto) {
                        piloto->unidade_tripulada.setHp(piloto->unidade_tripulada.getHp() + 15);
                        // As cartas em campo, que são tripuladas por pilotos genéricos da federação recebem +15 de vida.
                    }
                }
            }
            break;


        case 5: // Char Aznable
            // Percorre Campo
            for (int i = 0; i < jog.campo.size(); i++) {
                Piloto* piloto = dynamic_cast<Piloto*>(jog.campo[i]); //Dinamic cast
                if(piloto->getTipo()=="Heroi"){
                    contH++;
                }
                if (piloto->getTipo() == "Peao") { // Verifica se é um peão
                    indicesP.push_back(i); // Guarda o índice
                }
            }

            if(contH==1){ //O único herói é o próprio Char Aznable
                    for (int i = 0; i < indicesP.size(); i++) { // Percorre índices
                        Piloto* piloto = dynamic_cast<Piloto*>(jog.campo[indicesF[i]]);
                        if (piloto) {
                        piloto->unidade_tripulada.setHp(piloto->unidade_tripulada.getHp() + 20);
                        // As cartas em campo, que são tripuladas por pilotos tipo peao da federação recebem +20 de vida.
                        }
                }
            }
            break;

        case 6:// Dozle Zabi
            std::cout << "|\t - Se a sua unidade tripulada for do tipo heroi, voce pode gastar 2 de calor, e receber +15 pontos de ATK" <<std::endl;
            if(unidade_tripulada.getTipo()=="Heroi"){
                std::cout << "|\t - Selecione uma opcao;\n 0-Nao\n\t - 1-Sim\n";
                std::cin>>decide;
                if(decide==1 &&jog.getcalor()>=1){
                     jog.setcalor(jog.getcalor()-1); //Gasta  calor
                        unidade_tripulada.setAtk(unidade_tripulada.getAtk()+15); //Sobe o atk em 15 pontos
                }
                if(decide==0 || jog.getcalor()<1){
                    std::cout << "|\t - A acao nao sera realizada por escolha do jogador, ou porque o mesmo nao possui calor suficiente. " <<std::endl;
                    break;
                }}
            break;

        case 7: //Ramba Ral
            std::cout << "|\t - Deseja gastar 2 de calor, para receber evasao?"<<std::endl;
            std::cout << "|\t - 0-Nao\n\t - 1-Sim\n"<<std::endl;
            std::cin>>decide;
            if(decide==1 && jog.getcalor()>=2){
                jog.setcalor(jog.getcalor()-2);
                unidade_tripulada.ativaEvasao();
            }
            else{
                std::cout << "|\t - A acao nao sera realizada por escolha do jogador, ou porque o mesmo nao possui calor suficiente. " <<std::endl;
                break;
            }
            break;

        case 8: //Genérico Zeon
            // Percorre Campo
            for (int i = 0; i < jog.campo.size(); i++) {
                Piloto* piloto = dynamic_cast<Piloto*>(jog.campo[i]);
                if (piloto && piloto->getNome() == "Piloto de Zeon") { // Verifica se é um genérico dE ZEON
                    nPZ++; // Se sim, contabiliza em nPZ
                    indicesZ.push_back(i); // Guarda o índice
                }
            }

            if (nPZ >= 2) { // Se nPF é maior ou igual a 2
                for (int i = 0; i < indicesZ.size(); i++) { // Percorre índices
                    Piloto* piloto = dynamic_cast<Piloto*>(jog.campo[indicesF[i]]);
                    if (piloto) {
                        piloto->unidade_tripulada.setAtk(piloto->unidade_tripulada.getAtk() + 15);
                        // As cartas em campo, que são tripuladas por pilotos genéricos da federação recebem +15 de vida.
                    }
                }
            }
            break;

        default:
            break;
        } }

void Piloto::le(){
    std::cout << "| \t* Nome: "<< getNome() <<std::endl; //Imprime o nome
    std::cout << "| \t* Tipo: "<< getTipo() <<std::endl; //Imprime o tipo
    std::cout << "| \t* Descrição: "<< getDesc() <<std::endl; //Imprime a descrição
    std::cout << "| \t* Custo: "<< getCusto() <<std::endl; //Imprime o custo
    std::cout << "| \t* ID: "<< getID() <<std::endl; //Imprime o ID
    std::cout << "| \t* Efeito: "<< efeito_piloto <<std::endl; //Imprime o efeito
    std::cout << "| \t* Unidade Tripulada: "<< unidade_tripulada.getNome() <<std::endl; //Imprime a unidade tripulada
}

/*GETTERS E SETTERS*/
void Piloto::setUnidade(Unidade _unidade){
    unidade_tripulada = _unidade;
}

Unidade Piloto::getUnidade(){
    return unidade_tripulada;
}


    