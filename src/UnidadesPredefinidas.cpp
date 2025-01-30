#include "../include/Unidade.h"

namespace UnidadesPredefinidas {
     Unidade RX782Gundam = Unidade(50,  60, 7, "Mobile Suit desenvolvido em segredo pela Federação da Terra em 0079, Século Universal. Sua alta resistência e capacidades foram essenciais para a vitória federal na guerra de um ano.", "Lenda", "RX78-2 Gundam", false, 31, false); // Nome, HP, Ataque, Defesa...
     Unidade RX75Guntank = Unidade(25,  40, 4, "Mobile Suit desenvolvido pela Federação da Terra como parte da Operação V, em resposta às Mobile Suits desenvolvidas pelo Principado de Zeon. Esse modelo é dito ter controles e funcionalidades próximas a de um tanque convencional.", "Peao", "RX-75 Guntank", false, 32, false);
     Unidade Guncannon = Unidade(40,  30, 4, "Mobile Suit desenvolvido pela Federação da Terra como parte da Operação V, em resposta às Mobile Suits desenvolvidas pelo Principado de Zeon. Esse modelo favorece alcance e resistência sobre mobilidade e combate próximo.", "Peao", "RX77-2 Guncannon", false, 33, false);
     Unidade Ball = Unidade(10,  10, 2, "Uma reapropriação militar dos SP-W03 SPACE PODS, previamente usado em ambientes civis, pela Federação da Terra em 0079, Século Universal. Normalmente usado em esquadrões com outros Mobile Suits mais potentes.", "Peao", "RX79 Ball", false, 34, false);
     Unidade GM = Unidade(20,  20, 3, "Primeira linha de Mobile Suits produzida em massa pela Federação da Terra em 0079, Século Universal. Foi baseado nas informações de combate recolhidas do modelo RX-78-2 Gundam.", "Peao", "RGM-79 GM", false, 35, false);
     Unidade Zeong = Unidade(60,  80, 8, "Protótipo de Mobile Suit desenvolvido pelo Principado de Zeon em 0071, Século Universal. Originalmente planejado para ser usado por pilotos Newtype, MSN-02 Zeong possui comunicadores psíquicos para permitir manipulação completa de seus antebraços guiados por fios para encurralar inimigos a qualquer distância.", "tipo", "Zeong", false, 36, false);
     Unidade BigZam = Unidade(50,  70, 8, "Mobile Armor desenvolvida pelo Principado de Zeon em 0079, Século Universal. A carta na manga de Zeon nos estágios finais da guerra de um ano, Big Zam é a mais poderosa arma tática usada em todo o conflito.", "Lenda", "MA-08 Big Zam", false, 37, false);
     Unidade Gelgoog = Unidade(50, 50, 6, "Linha de produção em massa desenvolvida pelo Principado de Zeon em 0079, Século Universal. Criado para ser igual ou superar o RX-78-2 Gundam da Federação da Terra, MS-14A Gelgoog portava armamentos de lazer, como o rifle de assalto de raios e a Naginata de raios", "tipo", "Gelgoog", false, 38, false);
     Unidade ZGok = Unidade(0,  0, 0, "descricao", "tipo", "ZGok", false, 39, false);
     Unidade Gouf = Unidade(40,  40, 4, "Linha de Mobile Suits produzida pelo Principado de Zeon em 0079, Século Universal. Foi criado para combates terrenos de curto alcance, com mobilidade, salto e propulsores incrementados. Seu cabo de valor é um grande diferencial de demais linhas", "Peao", "MS-07B Gouf", false, 40, false);
     Unidade Zaku = Unidade(20, 20, 3, "Primeira linha de Mobile Suits produzida em Massa pelo Principado de Zeon em 0078, Século Universal. A máquina mais icônica de Zeon e suas ramificações, MS-06 Zaku II forneceu uma enorme vantagem a sua facção no começo da guerra de um ano", "Peao", "MS-06 Zaku II", false, 41, false);
}

//Unidade(int Atk, int Hp, int Custo, std::string Desc, std::string Tipo, std::string Nome, bool Equip, int ID, bool Guarda);

// arquivo de instanciação de objetos estáticos 