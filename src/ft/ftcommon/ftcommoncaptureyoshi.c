#include <ft/fighter.h>
#include <it/item.h>

extern void gcSetDObjAnimPlaybackRate(GObj*, f32);

// // // // // // // // // // // //
//                               //
//       INITIALIZED DATA        //
//                               //
// // // // // // // // // // // //

// 0x80188720
ftYoshiEggDesc dFTCommonYoshiEggHurtboxDescs[/* */] =
{
    { 2.0F, { 0.0F, 157.0F, 0.0F }, { 180.0F, 180.0F, 180.0F } },   // Mario
    { 1.9F, { 0.0F, 155.0F, 0.0F }, { 171.0F, 171.0F, 171.0F } },   // Fox
    { 3.5F, { 0.0F, 230.0F, 0.0F }, { 245.0F, 245.0F, 245.0F } },   // Donkey Kong
    { 2.2F, { 0.0F, 163.0F, 0.0F }, { 198.0F, 198.0F, 198.0F } },   // Samus
    { 2.2F, { 0.0F, 160.0F, 0.0F }, { 188.0F, 188.0F, 188.0F } },   // Luigi
    { 2.0F, { 0.0F, 133.0F, 0.0F }, { 148.0F, 148.0F, 148.0F } },   // Link
    { 2.5F, { 0.0F, 175.0F, 0.0F }, { 210.0F, 210.0F, 210.0F } },   // Yoshi
    { 2.2F, { 0.0F, 156.0F, 0.0F }, { 198.0F, 198.0F, 198.0F } },   // Captain Falcon
    { 1.8F, { 0.0F, 132.0F, 0.0F }, { 164.0F, 164.0F, 164.0F } },   // Kirby
    { 1.8F, { 0.0F, 144.0F, 0.0F }, { 165.0F, 165.0F, 165.0F } },   // Pikachu
    { 2.0F, { 0.0F, 144.0F, 0.0F }, { 162.0F, 162.0F, 162.0F } },   // Jigglypuff
    { 1.8F, { 0.0F, 160.0F, 0.0F }, { 168.0F, 168.0F, 168.0F } },   // Ness
    { 2.0F, { 0.0F, 157.0F, 0.0F }, { 180.0F, 180.0F, 180.0F } },   // Master Hand
    { 2.0F, { 0.0F, 157.0F, 0.0F }, { 180.0F, 180.0F, 180.0F } },   // Metal Mario
    { 2.0F, { 0.0F, 157.0F, 0.0F }, { 180.0F, 180.0F, 180.0F } },   // Poly Mario
    { 1.9F, { 0.0F, 155.0F, 0.0F }, { 171.0F, 171.0F, 171.0F } },   // Poly Fox
    { 3.5F, { 0.0F, 230.0F, 0.0F }, { 245.0F, 245.0F, 245.0F } },   // Poly Donkey Kong
    { 2.2F, { 0.0F, 163.0F, 0.0F }, { 198.0F, 198.0F, 198.0F } },   // Poly Samus
    { 2.2F, { 0.0F, 160.0F, 0.0F }, { 188.0F, 188.0F, 188.0F } },   // Poly Luigi
    { 2.0F, { 0.0F, 133.0F, 0.0F }, { 148.0F, 148.0F, 148.0F } },   // Poly Link
    { 2.5F, { 0.0F, 175.0F, 0.0F }, { 210.0F, 210.0F, 210.0F } },   // Poly Yoshi
    { 2.2F, { 0.0F, 156.0F, 0.0F }, { 198.0F, 198.0F, 198.0F } },   // Poly Captain Falcon
    { 1.8F, { 0.0F, 132.0F, 0.0F }, { 164.0F, 164.0F, 164.0F } },   // Poly Kirby
    { 1.8F, { 0.0F, 144.0F, 0.0F }, { 165.0F, 165.0F, 165.0F } },   // Poly Pikachu
    { 2.0F, { 0.0F, 144.0F, 0.0F }, { 162.0F, 162.0F, 162.0F } },   // Poly Jigglypuff
    { 1.8F, { 0.0F, 160.0F, 0.0F }, { 168.0F, 168.0F, 168.0F } },   // Poly Ness
    { 5.7F, { 0.0F, 400.0F, 0.0F }, { 350.0F, 350.0F, 350.0F } }    // Giant Donkey Kong
};

// // // // // // // // // // // //
//                               //
//           FUNCTIONS           //
//                               //
// // // // // // // // // // // //

// 0x8014C770
void func_ovl3_8014C770(void) // Unused
{
	return;
}

// 0x8014C778
void ftCommonCaptureYoshiProcPhysics(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);
    Vec3f pos;

    ftCommonCapturePulledRotateScale(fighter_gobj, &pos, &DObjGetStruct(fighter_gobj)->rotate.vec.f);

    DObjGetStruct(fighter_gobj)->translate.vec.f.x = pos.x;
    DObjGetStruct(fighter_gobj)->translate.vec.f.z = pos.z;

    if (fp->status_info.status_id == nFTCommonStatusCaptureYoshi)
    {
        if (fp->status_vars.common.captureyoshi.stage == 3)
        {
            ftCommonYoshiEggSetStatus(fighter_gobj);
        }
        else if (fp->status_vars.common.captureyoshi.stage == 1)
        {
            fp->status_vars.common.captureyoshi.stage = 2;

            fp->is_invisible = fp->x18E_flag_b0 = TRUE;

            ftParamSetHitStatusAll(fighter_gobj, nGMHitStatusIntangible);
        }
    }
}

// 0x8014C83C
void ftCommonCaptureYoshiProcCapture(GObj *fighter_gobj, GObj *capture_gobj)
{
    ftStruct *this_fp = ftGetStruct(fighter_gobj);
    ftStruct *capture_fp;

    ftParamStopVoiceRunProcDamage(fighter_gobj);

    if ((this_fp->item_hold != NULL) && (itGetStruct(this_fp->item_hold)->weight == nITWeightHeavy))
    {
        ftSetupDropItem(this_fp);
    }
    if (this_fp->catch_gobj != NULL)
    {
        ftCommonThrownSetStatusDamageRelease(this_fp->catch_gobj);

        this_fp->catch_gobj = NULL;
    }
    else if (this_fp->capture_gobj != NULL)
    {
        ftCommonThrownDecideFighterLoseGrip(this_fp->capture_gobj, fighter_gobj);
    }
    this_fp->x192_flag_b3 = FALSE;

    this_fp->capture_gobj = capture_gobj;

    capture_fp = ftGetStruct(capture_gobj);

    this_fp->lr = -capture_fp->lr;

    mpCommonSetFighterAir(this_fp);
    ftMainSetFighterStatus(fighter_gobj, nFTCommonStatusCaptureYoshi, 0.0F, 1.0F, FTSTATUS_PRESERVE_NONE);
    ftMainPlayAnimNoEffect(fighter_gobj);

    this_fp->status_vars.common.captureyoshi.stage = 0;
    this_fp->status_vars.common.captureyoshi.breakout_wait = 0;

    ftParamSetCaptureImmuneMask(this_fp, FTCATCHKIND_MASK_ALL);
    ftPhysicsStopVelAll(fighter_gobj);
    ftCommonCaptureYoshiProcPhysics(fighter_gobj);
    mpCommonUpdateFighterProjectGround(fighter_gobj);
}

// 0x8014C958
void ftCommonYoshiEggMakeEffect(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    if (fp->status_vars.common.captureyoshi.effect_gobj == NULL)
    {
        fp->status_vars.common.captureyoshi.effect_gobj = efManagerYoshiEggLayMakeEffect(fighter_gobj);

        if (fp->status_vars.common.captureyoshi.effect_gobj != NULL)
        {
            fp->is_attach_effect = TRUE;
        }
    }
}

// 0x8014C9A0
void ftCommonYoshiEggProcUpdate(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);
    sb32 is_escape = FALSE;

    if (fp->status_vars.common.captureyoshi.is_damagefloor == TRUE)
    {
        is_escape = TRUE;

        if (fp->status_vars.common.captureyoshi.effect_gobj != NULL)
        {
            ftParamProcStopEffect(fighter_gobj);

            fp->status_vars.common.captureyoshi.effect_gobj = NULL;
        }
    }
    else
    {
        ftCommonYoshiEggMakeEffect(fighter_gobj);

        if (fp->status_vars.common.captureyoshi.effect_gobj != NULL)
        {
            efStruct *ep = efGetStruct(fp->status_vars.common.captureyoshi.effect_gobj);

            if ((ep->effect_vars.yoshi_egg_lay.index == 1) && (fp->status_vars.common.captureyoshi.effect_gobj->anim_frame <= 0.0F))
            {
                is_escape = TRUE;
            }
        }
        else if (fp->command_vars.flags.flag0 == 1)
        {
            if (fp->status_vars.common.captureyoshi.breakout_wait-- <= 0)
            {
                is_escape = TRUE;
            }
        }
    }
    if (is_escape == TRUE)
    {
        Vec3f pos = DObjGetStruct(fighter_gobj)->translate.vec.f;

        pos.z = 0.0F;

        efManagerYoshiEggExplodeMakeEffect(&pos);
        efManagerEggBreakMakeEffect(&pos);
        func_800269C0_275C0(nGMSoundFGMYoshiEggLayShatter);

        fp->phys_info.vel_air.y = FTCOMMON_YOSHIEGG_ESCAPE_VEL_Y;
        fp->phys_info.vel_air.z = 0.0F;
        fp->phys_info.vel_air.x = 0.0F;

        DObjGetStruct(fighter_gobj)->translate.vec.f.y += FTCOMMON_YOSHIEGG_ESCAPE_OFF_Y;

        mpCommonSetFighterAir(fp);
        ftMainSetFighterStatus(fighter_gobj, nFTCommonStatusFall, 0.0F, 1.0F, FTSTATUS_PRESERVE_DAMAGEPLAYER);
        ftParamSetTimedHitStatusIntangible(fp, FTCOMMON_YOSHIEGG_INTANGIBLE_TIMER);
    }
}

// 0x8014CB24
void ftCommonYoshiEggProcInterrupt(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    if (fp->status_vars.common.captureyoshi.effect_gobj != NULL)
    {
        DObj *joint = DObjGetStruct(fp->status_vars.common.captureyoshi.effect_gobj)->child;

        if (fp->ga == nMPKineticsGround)
        {
            if (ABS(fp->input.pl.stick_range.y) >= FTCOMMON_YOSHIEGG_WIGGLE_STICK_RANGE_MIN)
            {
                joint->translate.vec.f.y = ((fp->input.pl.stick_range.y < 0) ? -1 : 1) * FTCOMMON_YOSHIEGG_WIGGLE_GFX_RANGE_XY;
            }
            else joint->translate.vec.f.y = 0.0F;

            if (ABS(fp->input.pl.stick_range.x) >= FTCOMMON_YOSHIEGG_WIGGLE_STICK_RANGE_MIN)
            {
                joint->translate.vec.f.x = ((fp->input.pl.stick_range.x < 0) ? -1 : 1) * FTCOMMON_YOSHIEGG_WIGGLE_GFX_RANGE_XY;
            }
            else joint->translate.vec.f.x = 0.0F;
        }
        else
        {
            joint->translate.vec.f.x = 0.0F;
            joint->translate.vec.f.y = 0.0F;
        }
    }
}

// 0x8014CC0C
void ftCommonYoshiEggProcPhysics(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    if (fp->command_vars.flags.flag0 == 0)
    {
        s32 breakout_wait = fp->breakout_wait;

        if (ftCommonCaptureTrappedUpdateBreakoutVars(fp) == TRUE)
        {
            if (fp->status_vars.common.captureyoshi.effect_gobj != NULL)
            {
                gcSetDObjAnimPlaybackRate(fp->status_vars.common.captureyoshi.effect_gobj, FTCOMMON_YOSHIEGG_WIGGLE_ANIM_SPEED);
            }
        }
        else if (fp->status_vars.common.captureyoshi.effect_gobj != NULL)
        {
            gcSetDObjAnimPlaybackRate(fp->status_vars.common.captureyoshi.effect_gobj, 1.0F);
        }
        fp->status_vars.common.captureyoshi.breakout_wait -= ((breakout_wait - fp->breakout_wait) * 12);

        if (fp->status_vars.common.captureyoshi.breakout_wait-- <= 0)
        {
            fp->command_vars.flags.flag0 = 1;
            fp->status_vars.common.captureyoshi.breakout_wait = FTCOMMON_YOSHIEGG_ESCAPE_WAIT_DEFAULT;
        }
    }
    if (fp->command_vars.flags.flag0 == 1)
    {
        if (fp->status_vars.common.captureyoshi.effect_gobj != NULL)
        {
            efStruct *ep = efGetStruct(fp->status_vars.common.captureyoshi.effect_gobj);

            ep->effect_vars.yoshi_egg_lay.force_index = 1;
        }
    }
    if (fp->ga == nMPKineticsGround)
    {
        ftPhysicsApplyGroundVelFriction(fighter_gobj);
    }
    else ftPhysicsApplyAirVelDriftFastFall(fighter_gobj);
}

// 0x8014CD24
void ftCommonYoshiEggProcMap(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    if (fp->ga == nMPKineticsGround)
    {
        if (mpCommonCheckFighterOnGround(fighter_gobj) == FALSE)
        {
            fp->ga = nMPKineticsAir;
        }
    }
    else if (mpCommonCheckFighterLanding(fighter_gobj) != FALSE)
    {
        fp->ga = nMPKineticsGround;
    }
}

// 0x8014CD7C
void ftCommonYoshiEggProcTrap(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    if (fp->command_vars.flags.flag0 == 0)
    {
        fp->status_vars.common.captureyoshi.breakout_wait -= ((2.0F * fp->damage_queue) / 0.5F);
    }
    if ((fp->damage_object_class == nFTHitlogObjectGround) && (fp->damage_object_kind == nGMHitEnvironmentAcid))
    {
        fp->status_vars.common.captureyoshi.breakout_wait = 0;
        fp->status_vars.common.captureyoshi.is_damagefloor = TRUE;
    }
    fp->damage_kind = nFTHitlogObjectGround;
}

// 0x8014CDFC
void ftCommonYoshiEggSetHurtCollisions(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);
    ftHurtbox *ft_hurt = &fp->fighter_hurt[0];
    ftYoshiEggDesc *egg = &dFTCommonYoshiEggHurtboxDescs[fp->ft_kind];
    s32 i;

    ft_hurt->joint = fp->joints[nFTPartsJointTopN];
    ft_hurt->joint_id = nFTPartsJointTopN;
    ft_hurt->placement = nFTPartsPlacementMiddle;
    ft_hurt->is_grabbable = FALSE;
    ft_hurt->offset = egg->offset;
    ft_hurt->size = egg->size;

    ft_hurt++;

    for (i = 1; i < ARRAY_COUNT(fp->fighter_hurt); i++, ft_hurt++)
    {
        if (ft_hurt->hitstatus != nGMHitStatusNone)
        {
            ft_hurt->hitstatus = nGMHitStatusIntangible;
        }
    }
    fp->is_hitstatus_nodamage = TRUE;
    fp->is_hurtbox_modify = TRUE;
}

// 0x8014CF0C
void ftCommonYoshiEggProcStatus(GObj *fighter_gobj)
{
    ftStruct *fp = ftGetStruct(fighter_gobj);

    fp->status_vars.common.captureyoshi.breakout_wait = FTCOMMON_YOSHIEGG_ESCAPE_WAIT_MAX;

    fp->command_vars.flags.flag0 = 0;
}

// 0x8014CF20
void ftCommonYoshiEggSetStatus(GObj *fighter_gobj)
{
    ftStruct *this_fp = ftGetStruct(fighter_gobj);
    ftStruct *capture_fp;

    if (this_fp->ga == nMPKineticsGround)
    {
        mpCommonSetFighterAir(this_fp);
    }
    this_fp->proc_status = ftCommonYoshiEggProcStatus;

    mpCommonSetFighterAir(this_fp);
    ftMainSetFighterStatus(fighter_gobj, nFTCommonStatusYoshiEgg, 0.0F, 0.0F, FTSTATUS_PRESERVE_NONE);
    ftParamSetCaptureImmuneMask(this_fp, FTCATCHKIND_MASK_ALL);

    this_fp->is_invisible = TRUE;

    ftCommonYoshiEggSetHurtCollisions(fighter_gobj);
    ftCommonCaptureTrappedInitBreakoutVars(this_fp, FTCOMMON_YOSHIEGG_BREAKOUT_INPUTS_MIN);
    ftKirbySpecialNApplyCaptureDamage(this_fp->capture_gobj, fighter_gobj, 5); // Br0h why
    ftParamSetPlayerTagWait(fighter_gobj, 1);

    capture_fp = ftGetStruct(this_fp->capture_gobj);

    DObjGetStruct(fighter_gobj)->translate.vec.f = DObjGetStruct(this_fp->capture_gobj)->translate.vec.f;

    DObjGetStruct(fighter_gobj)->translate.vec.f.x -= (capture_fp->lr * FTCOMMON_YOSHIEGG_LAY_OFF_X);
    DObjGetStruct(fighter_gobj)->translate.vec.f.y += FTCOMMON_YOSHIEGG_LAY_OFF_Y;

    mpCommonRunFighterCollisionDefault(fighter_gobj, &DObjGetStruct(this_fp->capture_gobj)->translate.vec.f, &ftGetStruct(this_fp->capture_gobj)->coll_data);

    this_fp->phys_info.vel_air.x = -capture_fp->lr * FTCOMMON_YOSHIEGG_LAY_VEL_X;
    this_fp->phys_info.vel_air.y = FTCOMMON_YOSHIEGG_LAY_VEL_Y;
    this_fp->damage_mul = FTCOMMON_YOSHIEGG_DAMAGE_MUL;

    this_fp->capture_gobj = NULL;

    this_fp->proc_trap = ftCommonYoshiEggProcTrap;

    this_fp->status_vars.common.captureyoshi.lr = capture_fp->lr;
    this_fp->status_vars.common.captureyoshi.effect_gobj = NULL;
    this_fp->status_vars.common.captureyoshi.is_damagefloor = FALSE;

    ftParamUpdate1PGameDamageStats(this_fp, capture_fp->player, nFTHitlogObjectFighter, capture_fp->ft_kind, capture_fp->stat_flags.halfword, capture_fp->stat_count);
    ftCommonYoshiEggMakeEffect(fighter_gobj);
}
