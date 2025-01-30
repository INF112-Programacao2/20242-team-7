#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <string>


// Forward declaration
class Jogador; // Apenas declara que Jogador existe

class Carta {
protected:
    std::string Descricao, Tipo, Nome;
    int ID, Custo;

public:
    // Métodos de acesso 
    virtual int getID();
    virtual int getCusto();
    virtual std::string getTipo();
    virtual void gasta_calor(int custo, Jogador &jogador);
    virtual void gera_calor(int qtd, Jogador &jogador);
    virtual void fornece_efeito();
    


    // Construtor e destrutor
    Carta(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
    virtual ~Carta() = 0; // Tornando a classe abstrata com destrutor puro virtual
};

#endif