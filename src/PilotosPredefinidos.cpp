#include "../include/Piloto.h"
#include "../include/Unidade.h"

namespace PilotosPredefinidos {

    Unidade unidadeVazia; // Unidade vazia para inicializacão

     Piloto AmuroRay = Piloto("Unidade que pilota recebe PV+25. Caso a Unidade Pilotada tenha o nome GUNDAM, a unidade recebe Evasão.",
                                   unidadeVazia, 
                                   "Um heroi da guerra de um ano, pilotou o Mobile Suit RX-78-2 GUNDAM no lado da Federacao da Terra. Também conhecido como \"Diabo Branco\"",
                                   "Piloto",
                                   "Amuro Ray",
                                   4,
                                   1);

     Piloto KayShiden = Piloto("Se a unidade tripulada for da forma \"Heroi\", ela recebe ATK+30",
                                    unidadeVazia,
                                    "Soldado da guerra de um ano, pilotou o RX-77-2 GUNCANNON do lado da federacao. Um dos quatro pilotos de Mobile Suit a bordo da White Base",
                                    "Piloto",
                                    "Kay Shiden",
                                    3,
                                    2);

     Piloto HayatoKobayashi = Piloto("Quando entra em campo, pode gastar 2 de calor para transformar sua unidade em uma copia de \"RX-75 GUNTANK\"",
                                          unidadeVazia,
                                          "Soldado da guerra de um ano, pilotou o RX-75 GUNTANK do lado da federacao. Um dos quatro pilotos de Mobile Suit a bordo da White Base",
                                          "Piloto",
                                          "Hayato Kobayashi",
                                          2,
                                          3);

     Piloto PilotoFederacao = Piloto("Caso existam 2 ou mais cópias de \"Piloto da federacao\" no campo, cada unidade pilotada por \"Piloto da federacao\" recebe PV+15",
                                          unidadeVazia,
                                          "Soldado sem nome lutando do lado da federacao da Terra na guerra de um ano. Treinado para operar as mobile suits federais, vários deles lutaram na fase final da guerra.",
                                          "Piloto",
                                          "Piloto da Federacao",
                                          1,
                                          4);

     Piloto CharAznable = Piloto("Pisiquico. Se for o único \"Heroi\" no seu campo, unidades do tipo \"Peao\" recebem PV+20",
                                      unidadeVazia,
                                      "Lendário soldado que lutou ao lado do Principiado de Zeon na guerra de um ano. A bordo do MS-06S ZAKU II Commander Type, foi um piloto essencial em toda a guerra. Também conhecido como o \"cometa vermelho\"",
                                      "Piloto",
                                      "Char Aznable",
                                      4,
                                      5);

     Piloto DozleZabi = Piloto("Efeito",
                                    unidadeVazia,
                                    "Um dos filhos da família Zabi, a dinastia que comandava o Principiado de Zeon. Durante a guerra de um ano, foi responsável pelas frotas espaciais Zeonicas, por vezes assumindo também o papel de piloto. Durante a batalha de Solomon, pilotou o MA-08 BIG ZAM",
                                    "Piloto",
                                    "Dozle Zabi",
                                    3,
                                    6);

     Piloto RambaRal = Piloto("Efeito",
                                   unidadeVazia,
                                   "RAMBA RAL: Aristocrata do Principiado de Zeon que se juntou à guerra de um ano como piloto de um MS-07B GOUF. Junto a sua amante, \"Crowley Hamon\", foi posicionado na Terra como parte do time de perseguicão da White Base",
                                   "Piloto",
                                   "Ramba Ral",
                                   2,
                                   7);

     Piloto PilotoZeon = Piloto("Caso existam 2 ou mais cópias de \"Piloto de Zeon\" no campo, cada unidade pilotada por \"Piloto de Zeon\" recebe ATK+15",
                                     unidadeVazia,
                                     "Piloto de Zeon: Soldado sem nome lutando do lado do Principiado de Zeon na guerra de um ano. Treinado para operar as mobile suits zeonicas, estavam presentes desde o comeco da guerra, representando uma grande ameaca para a federacao",
                                     "Piloto",
                                     "Piloto de Zeon",
                                     1,
                                     8);

}
