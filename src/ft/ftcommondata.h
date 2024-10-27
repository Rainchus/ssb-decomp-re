#ifndef _FTPROGRAMDATA_H_
#define _FTPROGRAMDATA_H_

// Massive file containing data from various files

#include <ssb_types.h>
#include <sys/obj.h>
#include <ft/fttypes.h>
#include <gm/gmtypes.h>

// 0x8012C830
extern f32 dFTCommonDataHandicapTable[/* */][2];

// 0x8012C970
extern u16 dFTCommonDataDownBounceSFX[/* */];

// 0x8012C9A8
extern u16 dFTCommonDataPublicityFighterChantFGMs[/* */];

// 0x8012C9E0
extern FTItemThrow dFTCommonDataItemThrowDescs[/* */];

// 0x8012CA38
extern FTItemSwing dFTCommonDataItemSwingAnimRates[/* */];

// 0x8012CA78
extern syColorRGBA dFTCommonDataShadowColorDefault;

// 0x8012CA7C
extern syColorRGBA dFTCommonDataShadowColorTeams[/* */];

// 0x8012DBD0
extern GMColDesc dFTCommonDataColAnimDescs[/* */]; // 0x8012DBD0

#endif
