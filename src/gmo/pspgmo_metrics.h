#ifndef __PSPGMO_METRICS_H__
#define __PSPGMO_METRICS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#include <pspgu.h>
#include <pspgum.h>

#include <pspgmo_format.h>

#ifdef __cplusplus
extern "C" {
#endif


//  metrics structure
typedef struct SceGmoMetrics SceGmoMetrics ;

struct SceGmoMetrics {
	int memory_size ;
	int memory_size2 ;

	int model_count ;
	int model_size ;

	int bone_count ;
	int bone_size ;
	int bone_morph_count ;
	int bone_blend_count ;
	int bone_part_count ;

	int part_count ;
	int part_size ;

	int mesh_count ;
	int mesh_size ;
	int mesh_material_count ;
	int mesh_blend_count ;
	int mesh_draw_count ;
	int mesh_prim_count ;
	int mesh_vertex_count ;
	int mesh_index_count ;
	int mesh_point_count ;
	int mesh_line_count ;
	int mesh_tri_count ;
	int mesh_rect_count ;
	int mesh_patch_count ;

	int arrays_count ;
	int arrays_size ;
	int arrays_morph_count ;
	int arrays_vertex_count ;

	int material_count ;
	int material_size ;

	int layer_count ;
	int layer_size ;
	int layer_texture_count ;

	int texture_count ;
	int texture_size ;

	int motion_count ;
	int motion_size ;
	int motion_anim_count ;

	int fcurve_count ;
	int fcurve_size ;
	int fcurve_key_count ;
} ;

//  metrics functions
int sceGmoModelGetMetrics( SceGmoMetrics *buf, int size, SceGmoChunk *chunk ) ;
int sceGmoModelGetMemoryClusterSize( SceGmoMetrics *buf, int size, int align ) ;
int sceGmoModelGetMemoryClusterSize2( SceGmoMetrics *buf, int size, int align ) ;

#ifdef __cplusplus
}
#endif

#endif
