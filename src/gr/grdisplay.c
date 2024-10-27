#include <gr/ground.h>

// // // // // // // // // // // //
//                               //
//       INITIALIZED DATA        //
//                               //
// // // // // // // // // // // //

// 0x8012E800
GRDisplayDesc dGRDisplayDescs[/* */] =
{
    // Layer 0
    {
        grDisplayLayer0PriFuncDisplay,
        grDisplayLayer0SecFuncDisplay,
        4,
        gcPlayAnimAll
    },

    // Layer 1
    {
        grDisplayLayer1PriFuncDisplay,
        grDisplayLayer1SecFuncDisplay,
        6,
        func_ovl2_800FBAD0
    },

    // Layer 2
    {
        grDisplayLayer2PriFuncDisplay,
        grDisplayLayer2SecFuncDisplay,
        13,
        gcPlayAnimAll
    },

    // Layer 3
    {
        grDisplayLayer3PriFuncDisplay,
        grDisplayLayer3SecFuncDisplay,
        17,
        gcPlayAnimAll
    }
};

// // // // // // // // // // // //
//                               //
//           FUNCTIONS           //
//                               //
// // // // // // // // // // // //

// 0x80104D90
void grDisplayLayer0PriFuncDisplay(GObj *ground_gobj)
{
    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPClearGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);

    gcDrawDObjTreeForGObj(ground_gobj);

    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPSetGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
}

// 0x80104E70
void grDisplayLayer0SecFuncDisplay(GObj *ground_gobj)
{
    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPClearGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPPipeSync(gSYTaskmanDLHeads[1]++);
    gSPClearGeometryMode(gSYTaskmanDLHeads[1]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[1]++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

    gcDrawDObjTreeDLLinksForGObj(ground_gobj);

    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPSetGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPPipeSync(gSYTaskmanDLHeads[1]++);
    gSPSetGeometryMode(gSYTaskmanDLHeads[1]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[1]++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
}

// 0x80104FD8
void grDisplayLayer1PriFuncDisplay(GObj *ground_gobj)
{
    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPSetGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPPipeSync(gSYTaskmanDLHeads[1]++);
    gDPSetRenderMode(gSYTaskmanDLHeads[1]++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);

    gcDrawDObjTreeForGObj(ground_gobj);
}

// 0x80105088
void grDisplayLayer1SecFuncDisplay(GObj *ground_gobj)
{
    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPSetGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    gDPPipeSync(gSYTaskmanDLHeads[1]++);
    gSPSetGeometryMode(gSYTaskmanDLHeads[1]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[1]++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);

    gcDrawDObjTreeDLLinksForGObj(ground_gobj);
}

// 0x80105154
void grDisplayLayer2PriFuncDisplay(GObj *ground_gobj)
{
    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPClearGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);

    gcDrawDObjTreeForGObj(ground_gobj);
}

// 0x801051D0
void grDisplayLayer2SecFuncDisplay(GObj *ground_gobj)
{
    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPClearGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPPipeSync(gSYTaskmanDLHeads[1]++);
    gSPClearGeometryMode(gSYTaskmanDLHeads[1]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[1]++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

    gcDrawDObjTreeDLLinksForGObj(ground_gobj);
}

// 0x80105290 - Identical to 0x80105154?
void grDisplayLayer3PriFuncDisplay(GObj *ground_gobj)
{
    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPClearGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);

    gcDrawDObjTreeForGObj(ground_gobj);
}

// 0x8010530C - Identical to 0x801051D0?
void grDisplayLayer3SecFuncDisplay(GObj *ground_gobj)
{
    gDPPipeSync(gSYTaskmanDLHeads[0]++);
    gSPClearGeometryMode(gSYTaskmanDLHeads[0]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[0]++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);

    gDPPipeSync(gSYTaskmanDLHeads[1]++);
    gSPClearGeometryMode(gSYTaskmanDLHeads[1]++, G_ZBUFFER);
    gDPSetRenderMode(gSYTaskmanDLHeads[1]++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);

    gcDrawDObjTreeDLLinksForGObj(ground_gobj);
}

// 0x801053CC
void grDisplayDObjSetNoAnimMtx(GObj *ground_gobj, DObjDesc *dobjdesc)
{
    DObj *root_dobj;
    DObj *next_dobj;
    s32 i;

    next_dobj = root_dobj = DObjGetStruct(ground_gobj);

    while (next_dobj != NULL)
    {
        if ((next_dobj->aobj == NULL) && !(dobjdesc->index & 0xF000))
        {
            for (i = 0; i < next_dobj->xobjs_num; i++)
            {
                next_dobj->xobj[i]->unk05 = 1;
            }
        }
        dobjdesc++;

        next_dobj = lbCommonGetTreeDObjNextFromRoot(next_dobj, root_dobj);
    }
}

// 0x8010547C
GObj* grDisplayMakeGeometryLayer(MPGroundDesc *gr_desc, s32 gr_desc_id, DObj **p_dobj)
{
    GObj *ground_gobj;
    void (*func_display)(GObj*);

    if (gr_desc->dobjdesc == NULL)
    {
        return NULL;
    }
    ground_gobj = gcMakeGObjSPAfter(nGCCommonKindGrRender, NULL, nGCCommonLinkIDGroundRender, GOBJ_LINKORDER_DEFAULT);

    if (gMPCollisionGroundData->layer_mask & (1 << gr_desc_id))
    {
        func_display = dGRDisplayDescs[gr_desc_id].func_displaysec;
    }
    else func_display = dGRDisplayDescs[gr_desc_id].func_displaypri;

    gcAddGObjDisplay(ground_gobj, func_display, dGRDisplayDescs[gr_desc_id].dl_link, GOBJ_DLLINKORDER_DEFAULT, -1);
    gcSetupCustomDObjs(ground_gobj, gr_desc->dobjdesc, p_dobj, nGCTransformTraRotRpyRSca, nGCTransformNull, nGCTransformNull);

    if (gr_desc->p_mobjsubs != NULL)
    {
        gcAddMObjAll(ground_gobj, gr_desc->p_mobjsubs);
    }
    if ((gr_desc->anim_joints != NULL) || (gr_desc->p_matanim_joints != NULL))
    {
        gcAddAnimAll(ground_gobj, gr_desc->anim_joints, gr_desc->p_matanim_joints, 0.0F);
        gcAddGObjProcess(ground_gobj, dGRDisplayDescs[gr_desc_id].proc_update, nGCProcessKindProc, 4);
        gcPlayAnimAll(ground_gobj);
    }
    else if (gr_desc_id == 1)
    {
        gcAddGObjProcess(ground_gobj, mpCollisionAdvanceUpdateFrame, nGCProcessKindProc, 4);
    }
    grDisplayDObjSetNoAnimMtx(ground_gobj, gr_desc->dobjdesc);

    return ground_gobj;
}
