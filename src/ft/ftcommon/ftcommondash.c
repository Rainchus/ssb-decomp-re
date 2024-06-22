#include <ft/fighter.h>

// // // // // // // // // // // //
//                               //
//           FUNCTIONS           //
//                               //
// // // // // // // // // // // //

// 0x8013EA40
void ftCommonDashProcUpdate(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    if (fighter_gobj->anim_frame <= 0.0F)
    {
        fp->phys_info.vel_ground.x *= 0.75F;

        ftCommon_Wait_SetStatus(fighter_gobj);
    }
}

// 0x8013EA90
void ftCommonDashProcInterrupt(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    if ((fp->command_vars.flags.flag1 != 0) && (fighter_gobj->anim_frame <= 5.0F))
    {
        if 
        (
            (ftCommonSpecialNCheckInterruptCommon(fighter_gobj) == FALSE) && 
            (ftCommonCatchCheckInterruptCommon(fighter_gobj) == FALSE)    &&
            (ftCommonAttackS4CheckInterruptDash(fighter_gobj) == FALSE)
        )
        {
            if ((fighter_gobj->anim_frame <= 3.0F) && (ftCommonEscapeCheckInterruptDash(fighter_gobj) != FALSE))
            {
                return;
            }
            else if (ftCommonGuardOnCheckInterruptCommon(fighter_gobj) != FALSE) // Jump interrupt?
            {
                return;
            }
            else goto next;
        }
    }
    else if (fighter_gobj->anim_frame <= 20.0F)
    {
        if (ftCommonSpecialNCheckInterruptCommon(fighter_gobj) == FALSE)
        {
            if (ftCommonCatchCheckInterruptDashRun(fighter_gobj) == FALSE)
            {
                if
                (
                    (ftCommonAttackDashCheckInterruptCommon(fighter_gobj) == FALSE) && 
                    (
                        ((fp->input.pl.stick_range.x * fp->lr) >= 0) || (ftCommonDashCheckInterruptCommon(fighter_gobj) == FALSE)
                    )
                )
                {
                    if (ftCommonGuardOnCheckInterruptDashRun(fighter_gobj, 20.0F - fighter_gobj->anim_frame) != FALSE)
                    {
                        return;
                    }
                    else goto next;
                }
            }
        }
    }
    else if 
    (
        (ftCommonCatchCheckInterruptCommon(fighter_gobj) == FALSE)  && 
        (ftCommonDashCheckInterruptCommon(fighter_gobj) == FALSE)   &&
        (ftCommonGuardOnCheckInterruptCommon(fighter_gobj) == FALSE)
    )
    {
    next:
        if ((ftCommonAppealCheckInterruptCommon(fighter_gobj) == FALSE) && (ftCommonKneeBendCheckInterruptRun(fighter_gobj) == FALSE))
        {
            ftCommonRunCheckInterruptDash(fighter_gobj);
        }
    }
}

// 0x8013EC58
void ftCommonDashProcPhysics(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);
    ftAttributes *attributes = fp->attributes;

    if (fighter_gobj->anim_frame >= FTCOMMON_DASH_DECELERATE_BEGIN)
    {
        ftPhysics_SetGroundVelFriction(fp, attributes->dash_decelerate);
    }
    ftPhysics_SetGroundVelTransferAir(fighter_gobj);
}

// 0x8013ECB0
void ftCommonDashProcMap(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);
    ftAttributes *attributes = fp->attributes;

    if (attributes->dash_to_run <= fighter_gobj->anim_frame)
    {
        ftMap_CheckGroundEdgeOttottoOrFall(fighter_gobj);
    }
    else ftMap_CheckGroundBreakSetFall(fighter_gobj);
}

// 0x8013ED00
void ftCommonDashSetStatus(GObj *fighter_gobj, u32 flag)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    ftMainSetFighterStatus(fighter_gobj, ftStatus_Common_Dash, 0.0F, 1.0F, FTSTATUPDATE_NONE_PRESERVE);
    ftMainUpdateAnimCheckInterrupt(fighter_gobj);

    fp->phys_info.vel_ground.x = fp->attributes->dash_speed;
    fp->tap_stick_x = FTINPUT_STICKBUFFER_FRAMES_MAX;
    fp->command_vars.flags.flag1 = flag;
}

// 0x8013ED64
sb32 ftCommonDashCheckInterruptCommon(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    if ((ABS(fp->input.pl.stick_range.x) >= FTCOMMON_DASH_STICK_RANGE_MIN) && (fp->tap_stick_x < FTCOMMON_DASH_BUFFER_FRAMES_MAX))
    {
        if ((fp->input.pl.stick_range.x * fp->lr) < 0)
        {
            ftCommonTurnSetStatusInvertLR(fighter_gobj);

            return TRUE;
        }
        ftCommon_StickInputSetLR(fp);
        ftCommonDashSetStatus(fighter_gobj, 1);

        return TRUE;
    }
    return FALSE;
}

// 0x8013EDFC
sb32 ftCommonDashCheckTurn(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    if (((fp->input.pl.stick_range.x * fp->status_vars.common.turn.lr_turn) >= FTCOMMON_DASH_STICK_RANGE_MIN) && (fp->tap_stick_x < FTCOMMON_DASH_BUFFER_FRAMES_MAX))
    {
        fp->status_vars.common.turn.lr_dash = fp->status_vars.common.turn.lr_turn;
        fp->status_vars.common.turn.attacks4_buffer = 0;

        return TRUE;
    }
    else return FALSE;
}
