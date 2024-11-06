#ifndef _MPTYPES_H_
#define _MPTYPES_H_

#include <ssb_types.h>
#include <macros.h>
#include <sys/obj.h>
#include <gm/generic.h>
#include <mp/mpdef.h>

// Room = collection of groups
// Group = collection of lines
// Line = collection of vertices

struct MPVertexInfo
{
	u8 yakumono_id;
	u8 line_type;
	s16 coll_pos_next;
	s16 coll_pos_prev;
	s16 edge_psign_id; // PSign = positive sign -> collision types that use +1
					   // for orientation (Upper/Ground and Right)
	s16 edge_nsign_id; // NSign = negative sign -> collision types that use -1
					   // for orientation (Under/Down/Ceil and Left)
};

struct MPVertexLinks
{
	u16 vertex1, vertex2;
};

struct MPVertexArray
{
	u16 vertex_id[1];
};

struct MPVertexData
{
	Vec2h pos;
	u16 vertex_flags; // upper 8 bits = surface type (e.g. drop-through,
					  // cliff), lower 8 bits = material (e.g. normal, damaging
					  // floor, etc.)
};

struct MPVertexPosContainer
{
	MPVertexData vpos[1];
};

struct MPLineData
{
	u16 group_id;
	u16 line_count; // Number of lines with collision type? e.g. there are 4
					// ground lines on Saffron City in the main group
};

struct MPLineInfo
{
	u16 yakumono_id; // Group that this line
	MPLineData line_data[4];
};

struct MPGeometryData // 0x80131368
{
	u16 yakumono_count;
	void* vertex_data;
	void* vertex_id;
	void* vertex_links;
	MPLineInfo* line_info;
	u16 mapobj_count;
	void* mapobjs;
};

struct MPVertexInfoContainer
{
	MPVertexInfo vertex_info[1];
};

struct MPVertexLinksContainer
{
	MPVertexLinks vertex_links[1];
};

struct MPYakumonoDObj
{
	DObj *yakumono_dobj[1];
};

struct MPMapObjData
{
	u16 mapobj_kind;
	Vec2h pos;
};

struct MPMapObjContainer
{
	MPMapObjData mapobjs[1];
};

struct MPLineGroup // This is all getting hard to wrap one's head around, but
				   // this is basically a group of line types (ground, ceil,
				   // rwall, lwall)
{
	u16 line_count, *line_id;
};

struct MPDirection
{
	f32 top, bottom, right, left;
};

struct MPEdgeBounds
{
	MPDirection d0, d1, d2, d3;
};

struct MPObjectColl
{
	f32 top;
	f32 center;
	f32 bottom;
	f32 width;
};

struct MPCollData
{
	Vec3f* p_translate;			 	// Points to object's TopN translation vector
	s32* p_lr;					 	// Points to object's facing direction sign
	Vec3f pos_curr;				// Main object collision position
	Vec3f pos_correct;			 	// Unconfirmed
	Vec3f pos_speed;			 	// Applied from moving collisions
	Vec3f vel_push;				 	// Applied from extern stage objects such as Whispy's Wind
	MPObjectColl map_coll;	 		// Environmental collision box
	MPObjectColl *p_map_coll; 		// Points back to environmental collision box???
	Vec2f cliffcatch_coll;		 	// Ledge grab collision box
	u16 coll_mask_prev;			 	// Previous collision flags?
	u16 coll_mask_curr;			// Current collision flags
	u16 coll_mask_unk;			 	// ???
	u16 coll_mask_stat;			 	// Used exclusively by object to transition between
								 	// action states? Also, persists unlike the above three.
	u16 coll_update_frame;		 	// Updates each frame?
	s32 ewall_line_id;			 	// Line ID of wall that is right under the ledge the
								 	// object is standing on?
	sb32 is_coll_end;			 	// Collision task completion bool? Main collision loop's
								 	// second condition is that this is FALSE
	Vec3f line_coll_dist;	 		// Distance to nearest collision?

	s32 ground_line_id; 			// Ground collision line ID
	f32 ground_dist;				// Distance to ground collision directly under object
	u32 ground_flags;				// Ground collision attributes
	Vec3f ground_angle; 			// Ground collision angle

	s32 ceil_line_id; 				// Ceiling collision line ID
	u32 ceil_flags;	  				// Ceiling collision attributes
	Vec3f ceil_angle; 				// Ceiling collision angle

	s32 lwall_line_id; 				// Left Wall collision line ID
	u32 lwall_flags;   				// Left Wall collision attributes
	Vec3f lwall_angle; 				// Left Wall collision angle

	s32 rwall_line_id; 				// Right Wall collision line ID
	u32 rwall_flags;   				// Right Wall collision attributes
	Vec3f rwall_angle; 				// Right Wall collision angle

	s32 cliff_id;					// Ledge ID
	s32 ignore_line_id; 			// Ignore this line when checking for collision
};

struct MPItemWeights
{
    u8 item_quantities[1];
};

struct MPGroundDesc
{
	void *dobjdesc;
	AObjEvent32 **anim_joints;
	MObjSub ***p_mobjsubs;
	AObjEvent32 ***p_matanim_joints;
};

struct MPGroundData
{
	MPGroundDesc gr_desc[4];
	MPGeometryData *map_geometry;
	u8 layer_mask; // render mask which determines render type for each geo layer (gr_desc) - 0 = primary, 1 = secondary (more alpha control w/2 display lists)
	Sprite *wallpaper; 								// Background image?
	SYColorRGB fog_color;
	u8 fog_alpha;								 	// Unused padding?
	SYColorRGB emblem_colors[GMCOMMON_PLAYERS_MAX]; 	// What's this doing here?
	s32 unk_0x5C;
	Vec3f light_angle;
	s16 camera_bound_top;				// Normal bounds
	s16 camera_bound_bottom;
	s16 camera_bound_right;
	s16 camera_bound_left;
	s16 map_bound_top;
	s16 map_bound_bottom;
	s16 map_bound_right;
	s16 map_bound_left;
	u32 bgm_id;
	void *map_nodes;
	MPItemWeights *item_weights; 	// Randomizer weights of items
	s16 alt_warning;				// Warning whistle plays if a player goes below this altitude
	s16 camera_bound_team_top;			// 1P Game VS. <character> Team bounds
	s16 camera_bound_team_bottom;
	s16 camera_bound_team_right;
	s16 camera_bound_team_left;
	s16 map_bound_team_top;
	s16 map_bound_team_bottom;
	s16 map_bound_team_right;
	s16 map_bound_team_left;
	Vec3h unk_groundinfo_0x9A;
	Vec3h unk_groundinfo_0xA0;
};

#endif
