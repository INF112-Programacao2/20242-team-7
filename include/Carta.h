#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <vector>
#include <string>


// Forward declaration
class Jogador; // Apenas declara que Jogador existe

class Carta {
protected:
    std::string Descricao, Tipo, Nome;
    int ID, Custo;
    bool equipavel = false;

public:
    // Métodos de acesso 
    virtual int getID();
    virtual int getCusto();
    virtual std::string getTipo();
    virtual std::string getNome();
    virtual std::string getDesc();
    virtual void le();
    virtual void infoBasica();
    virtual bool getEquipavel();
    virtual void setEquipavel(bool equip);
    virtual void gasta_calor(int custo, Jogador &jogador);
    virtual void gera_calor(int qtd, Jogador &jogador);
    virtual void fornece_efeito();
    virtual void setCusto(int custo);
    virtual bool operator==(const Carta& other) const;
    


    // Construtor e destrutor
    Carta(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID);
    Carta(std::string _Desc, std::string _Tipo, std::string _Nome, int _Custo, int _ID, bool _Equip);
    virtual ~Carta() = 0; // Tornando a classe abstrata com destrutor puro virtual
};

#endif