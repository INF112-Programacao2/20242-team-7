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
     Equipamento GundamHammer = Equipamento(30, 0, false, "Desc",  "Equipamento",  "Gundam Hammer",  3, 31);
     Equipamento ArmaduraChobam = Equipamento(0, 10, true, "Desc",  "Equipamento",  "Armadura de Chobam",  4, 32);
     Equipamento UpgradeGundam = Equipamento(-20, -10, false, "Desc",  "Equipamento",  "Upgrade para o Gundam",  4, 33);
     Equipamento ReatorPartículasMinovsky = Equipamento(3, 0, false, 1, "Desc",  "Equipamento",  "Reator de Partículas Minovsky",  3, 34);
}