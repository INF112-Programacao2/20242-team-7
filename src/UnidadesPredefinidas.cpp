#include "../include/Unidade.h"

namespace UnidadesPredefinidas {
     Unidade RX782Gundam = Unidade(50,  60, 7, "Mobile Suit desenvolvido em segredo pela Federacao da Terra em 0079, Seculo Universal. Sua alta resistência e capacidades foram essenciais para a vitoria federal na guerra de um ano.", "Lenda", "RX78-2 Gundam", false, 31, false); // Nome, HP, Ataque, Defesa...
     Unidade RX75Guntank = Unidade(25,  40, 4, "Mobile Suit desenvolvido pela Federacao da Terra como parte da Operacao V, em resposta às Mobile Suits desenvolvidas pelo Principado de Zeon. Esse modelo e dito ter controles e funcionalidades proximas a de um tanque convencional.", "Peao", "RX-75 Guntank", false, 32, false);
     Unidade Guncannon = Unidade(40,  30, 4, "Mobile Suit desenvolvido pela Federacao da Terra como parte da Operacao V, em resposta às Mobile Suits desenvolvidas pelo Principado de Zeon. Esse modelo favorece alcance e resistência sobre mobilidade e combate proximo.", "Peao", "RX77-2 Guncannon", false, 33, false);
     Unidade Ball = Unidade(10,  10, 2, "Uma reapropriacao militar dos SP-W03 SPACE PODS, previamente usado em ambientes civis, pela Federacao da Terra em 0079, Seculo Universal. Normalmente usado em esquadrões com outros Mobile Suits mais potentes.", "Peao", "RX79 Ball", false, 34, false);
     Unidade GM = Unidade(20,  20, 3, "Primeira linha de Mobile Suits produzida em massa pela Federacao da Terra em 0079, Seculo Universal. Foi baseado nas informacões de combate recolhidas do modelo RX-78-2 Gundam.", "Peao", "RGM-79 GM", false, 35, false);
     Unidade Zeong = Unidade(60,  80, 8, "Prototipo de Mobile Suit desenvolvido pelo Principado de Zeon em 0071, Seculo Universal. Originalmente planejado para ser usado por pilotos Newtype, MSN-02 Zeong possui comunicadores psiquicos para permitir manipulacao completa de seus antebracos guiados por fios para encurralar inimigos a qualquer distância.", "Heroi", "Zeong", false, 36, false);
     Unidade BigZam = Unidade(50,  70, 8, "Mobile Armor desenvolvida pelo Principado de Zeon em 0079, Seculo Universal. A carta na manga de Zeon nos estagios finais da guerra de um ano, Big Zam e a mais poderosa arma tatica usada em todo o conflito.", "Lenda", "MA-08 Big Zam", false, 37, false);
     Unidade Gelgoog = Unidade(50, 50, 6, "Linha de producao em massa desenvolvida pelo Principado de Zeon em 0079, Seculo Universal. Criado para ser igual ou superar o RX-78-2 Gundam da Federacao da Terra, MS-14A Gelgoog portava armamentos de lazer, como o rifle de assalto de raios e a Naginata de raios", "Heroi", "Gelgoog", false, 38, false);
     Unidade ZGok = Unidade(20,  15, 3, "Nao se sabe muito sobre ZGok...", "Undefined", "ZGok", false, 39, false);
     Unidade Gouf = Unidade(40,  40, 4, "Linha de Mobile Suits produzida pelo Principado de Zeon em 0079, Seculo Universal. Foi criado para combates terrenos de curto alcance, com mobilidade, salto e propulsores incrementados. Seu cabo de valor e um grande diferencial de demais linhas", "Peao", "MS-07B Gouf", false, 40, false);
     Unidade Zaku = Unidade(20, 20, 3, "Primeira linha de Mobile Suits produzida em Massa pelo Principado de Zeon em 0078, Seculo Universal. A maquina mais icônica de Zeon e suas ramificacões, MS-06 Zaku II forneceu uma enorme vantagem a sua faccao no comeco da guerra de um ano", "Peao", "MS-06 Zaku II", false, 41, false);
}

//Unidade(int Atk, int Hp, int Custo, std::string Desc, std::string Tipo, std::string Nome, bool Equip, int ID, bool Guarda);

// arquivo de instanciação de objetos estáticos 