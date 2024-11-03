#include <gr/ground.h>
#include <sc/scene.h>

// // // // // // // // // // // //
//                               //
//       INITIALIZED DATA        //
//                               //
// // // // // // // // // // // //

// 0x8012E840
GObj* (*dGRMainSetupProcMakeList[/* */])(void) =
{
    grCastleMakeGround,
    grSectorMakeGround,
    grJungleMakeGround,
    grZebesMakeGround,
    grHyruleMakeGround,
    grYosterMakeGround,
    grPupupuMakeGround,
    grYamabukiMakeGround,
    grInishieMakeGround
};

// // // // // // // // // // // //
//                               //
//           FUNCTIONS           //
//                               //
// // // // // // // // // // // //

// 0x801056C0
void grMainSetupMakeGround(void) // New file
{
    if (gSCManagerBattleState->gkind <= nGRKindBattleEnd)
    {
        dGRMainSetupProcMakeList[gSCManagerBattleState->gkind]();
    }
    else if (gSCManagerBattleState->gkind == nGRKindBonus3)
    {
        grBonus3MakeGround();
    }
    else if (gSCManagerBattleState->gkind >= nGRKindBonus2Start)
    {
        func_ovl6_8018DC38();
    }
    else if (gSCManagerBattleState->gkind >= nGRKindBonus1Start)
    {
        func_ovl6_8018D5C8();
    }
}