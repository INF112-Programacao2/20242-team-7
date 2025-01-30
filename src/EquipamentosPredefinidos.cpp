#include "../include/Equipamento.h"

/*
int atk_extra,
 int hp_extra,
 bool _guarda,
 calor_extra,
 std::string _Desc,
 std::string _Tipo,
 std::string _Nome,
 int _Custo,
 int _ID

*/

namespace EquipamentosPredefinidos{
     Equipamento GundamHammer = Equipamento(30, 0, false, "'Estou enviando a gundam hammer, você está pronto?' - Sayla Mass ",  "Equipamento",  "Gundam Hammer",  3, 42);
     Equipamento ArmaduraChobam = Equipamento(0, 10, true, "'Você tem que ser um tipo de aberração pra pilotar essa coisa' - Engenheiro",  "Equipamento",  "Armadura de Chobam",  4, 43);
     Equipamento UpgradeGundam = Equipamento(-20, -10, false, "'Ele melhorou o Gundam imensamente...não é Amuro?' - Tem Ray ",  "Equipamento",  "Upgrade para o Gundam",  4, 44);
     Equipamento ReatorPartículasMinovsky = Equipamento(3, 0, false, 1, "'Usá-lo suaviza o sistema de controle e torna possível o controle ativo de altitude'- Trenov Y. Minovsky",  "Equipamento",  "Reator de Particulas Minovsky",  3, 45);
}