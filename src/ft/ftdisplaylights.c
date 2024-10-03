#include <ft/fighter.h>
#include <sys/malloc.h>

// // // // // // // // // // // //
//                               //
//       EXTERNAL VARIABLES      //
//                               //
// // // // // // // // // // // //

extern syMallocRegion gSYTaskGraphicsHeap;

// // // // // // // // // // // //
//                               //
//           FUNCTIONS           //
//                               //
// // // // // // // // // // // //

// 0x800FCB70
void ftDisplayLightsDrawReflect(Gfx **display_list, f32 light_angle_x, f32 light_angle_y)
{
    Vec3f vec;

    vec.y = -lbCommonSin(-F_CLC_DTOR32(light_angle_y));
    vec.z = lbCommonCos(-F_CLC_DTOR32(light_angle_y));
    vec.x = lbCommonSin(F_CLC_DTOR32(light_angle_x)) * vec.z;
    vec.z *= lbCommonCos(F_CLC_DTOR32(light_angle_x));

    ((Light*)gSYTaskGraphicsHeap.ptr)->l.dir[0] = vec.x * 100.0F;
    ((Light*)gSYTaskGraphicsHeap.ptr)->l.dir[1] = vec.y * 100.0F;
    ((Light*)gSYTaskGraphicsHeap.ptr)->l.dir[2] = vec.z * 100.0F;

    gSPNumLights(display_list[0]++, 1);
    gSPLight(display_list[0]++, gSYTaskGraphicsHeap.ptr, 1);

    gSYTaskGraphicsHeap.ptr = (Light*)gSYTaskGraphicsHeap.ptr + 1;
}