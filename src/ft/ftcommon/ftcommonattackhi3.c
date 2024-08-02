#include <ft/fighter.h>

// // // // // // // // // // // //
//                               //
//           FUNCTIONS           //
//                               //
// // // // // // // // // // // //

// 0x8014FA50
void ftCommonAttackHi3SetStatus(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);
    f32 stick_angle;
    s32 status_id;

    if (fp->ft_data->gamemotion->script_info[nFTCommonMotionAttackHi3F].anim_file_id != 0)
    {
        stick_angle = atan2f(fp->input.pl.stick_range.y, fp->input.pl.stick_range.x * fp->lr);

        status_id = (stick_angle < F_CLC_DTOR32( 77.0F)) /* 1.3439035F */ ? nFTCommonStatusAttackHi3F : // WHAT
                    (stick_angle > F_CLC_DTOR32(103.0F)) /* 1.7976892F */ ? nFTCommonStatusAttackHi3B : // WHAT
                                                                            nFTCommonStatusAttackHi3;
    }
    else status_id = nFTCommonStatusAttackHi3;

    ftMainSetFighterStatus(fighter_gobj, status_id, 0.0F, 1.0F, FTSTATUS_PRESERVE_NONE);
    ftMainPlayAnimNoEffect(fighter_gobj);
}

// 0x8014FB1C
sb32 ftCommonAttackHi3CheckInterruptCommon(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);
    ftAttributes *attributes = fp->attributes;

    if ((fp->input.pl.button_tap & fp->input.button_mask_a) && (fp->input.pl.stick_range.y >= FTCOMMON_ATTACKHI3_STICK_RANGE_MIN))
    {
        if (ftParamGetStickAngleRads(fp) > F_CST_DTOR32(50.0F)) // 0.87266463F
        {
            if (ftCommonLightThrowCheckItemTypeThrow(fp) != FALSE)
            {
                ftCommonItemThrowSetStatus(fighter_gobj, nFTCommonStatusLightThrowHi);

                return TRUE;
            }
            else if (attributes->is_have_attackhi3)
            {
                ftCommonAttackHi3SetStatus(fighter_gobj);

                return TRUE;
            }
        }
    }
    return FALSE;
}
