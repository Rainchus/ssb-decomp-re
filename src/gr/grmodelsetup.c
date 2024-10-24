#include <gr/ground.h>

// // // // // // // // // // // //
//                               //
//           FUNCTIONS           //
//                               //
// // // // // // // // // // // //

// 0x80105760
void grModelSetupGroundDObjs(GObj *gobj, DObjDesc *dobjdesc, DObj **dobjs, DObjTransformTypes *transform_types)
{
    s32 i, id;
    DObj *dobj, *array_dobjs[DOBJ_ARRAY_MAX];

    for (i = 0; i < ARRAY_COUNT(array_dobjs); i++)
    {
        array_dobjs[i] = NULL;
    }
    for (i = 0; dobjdesc->index != ARRAY_COUNT(array_dobjs); i++, dobjdesc++)
    {
        id = dobjdesc->index & 0xFFF;

        if (id != 0)
        {
            dobj = array_dobjs[id] = gcAddChildForDObj(array_dobjs[id - 1], dobjdesc->display_list);
        }
        else dobj = array_dobjs[0] = gcAddDObjForGObj(gobj, dobjdesc->display_list);
        
        if (transform_types[i].tk1 != nGCTransformNull)
        {
            gcAddGCMatrixForDObjFixed(dobj, transform_types[i].tk1, transform_types[i].tk3);
        }
        if (transform_types[i].tk2 != nGCTransformNull)
        {
            gcAddGCMatrixForDObjFixed(dobj, transform_types[i].tk2, 0);
        }
        dobj->translate.vec.f = dobjdesc->translate;
        dobj->rotate.vec.f = dobjdesc->rotate;
        dobj->scale.vec.f = dobjdesc->scale;

        if (dobjs != NULL)
        {
            dobjs[i] = dobj;
        }
    }
}
