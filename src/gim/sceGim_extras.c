
//used calculate image width and height
static __inline__ int sceGimPicturePow2( int num )
{
	union { float f; int i; } u;
	u.f = (float)num - 0.5f;
	return 1 << ( ( u.i >> 23 ) - 126 );
}

//unused
static __inline__ int sceGimPictureCLZ( int num )
{
	int i;
	for ( i = 31; i >= 0; -- i )
	{
		if ( ( 1 << i ) & num )
		{
			return 31 - i;
		}
	}
	return 32;
}

//unused
static __inline__ int sceGimPictureCTZ( int num )
{
	int i;
	for ( i = 0; i <= 31; i ++ )
	{ 
		if ( ( 1 << i ) & num )
		{ 
			return i;
		}
	}
	return 32;
}

//-----------------FORMAT-----------------
//get the format of a gim image
static __inline__ int sceGimImageGetFormat( const SceGimImageHeader *image )
{
	return image->format;
}

//set the format of a gim image
static __inline__ void sceGimImageSetFormat( const SceGimImageHeader *image, unsigned short format )
{
	image->format = format;
}

//-----------------ORDER-----------------
//get the order of a gim image
static __inline__ int sceGimImageGetOrder( const SceGimImageHeader *image )
{
	return image->order;
}

//set the order of a gim image
static __inline__ void sceGimImageSetOrder( const SceGimImageHeader *image, unsigned short bpp )
{
	image->order = order;
}

//-----------------BPP-----------------
//get the bpp of a gim image
static __inline__ int sceGimImageGetBPP( const SceGimImageHeader *image )
{
	return image->bpp;	// bits per pixel 
}

//set the bpp of a gim image
static __inline__ void sceGimImageSetBPP( const SceGimImageHeader *image, unsigned short bpp )
{
	image->bpp = bpp;	// bits per pixel 
}

//-----------------IMAGE WIDTH-----------------
//get the gim image width
static __inline__ int sceGimImageGetWidth( const SceGimImageHeader *image, int level )
{
	int width = image->width;
	if ( level > 0 && image->level_type == SCEGIM_TYPE_MIPMAP ) {
		while ( -- level >= 0 ) width = ( width + 1 ) / 2;
	}
	return width;
}

//set the gim image width
static __inline__ void sceGimImageSetWidth( const SceGimImageHeader *image, unsigned short width )
{
	image->width = width;
}

//-----------------IMAGE HEIGHT-----------------
//get the gim image height
static __inline__ int sceGimImageGetHeight( const SceGimImageHeader *image, int level )
{
	int height = image->height;
	if ( level > 0 && image->level_type == SCEGIM_TYPE_MIPMAP ) {
		while ( -- level >= 0 ) height = ( height + 1 ) / 2;
	}
	return height;
}

//set the gim image height
static __inline__ void sceGimImageSetHeight( const SceGimImageHeader *image, unsigned short height )
{
	image->height = height;
}

//-----------------IMAGE PITCH-----------------
//get the gim image pitch
static __inline__ int sceGimImageGetPitch( const SceGimImageHeader *image, int width )
{
	int align = image->pitch_align * 8 - 1;
	return ( ( image->bpp * width + align ) & ~align ) / 8;
}

//set the gim image pitch
static __inline__ void sceGimImageSetPitch( const SceGimImageHeader *image, unsigned short pitch_align )
{
	image->pitch_align = pitch_align;
}

//-----------------BUFFER WIDTH-----------------
//get the gim image buffer width
static __inline__ int sceGimImageGetBufWidth( const SceGimImageHeader *image, int width )
{
	int align = image->pitch_align * 8 / image->bpp - 1;
	return ( width + align ) & ~align;
}

//set the gim image buffer width
static __inline__ void sceGimImageSetBufWidth( const SceGimImageHeader *image, unsigned short pitch_align )
{
	image->pitch_align = pitch_align;
}

//-----------------BUFFER HEIGHT-----------------
//get the gim image buffer height
static __inline__ int sceGimImageGetBufHeight( const SceGimImageHeader *image, int height )
{
	int align = image->height_align - 1;
	return ( height + align ) & ~align;
}

//set the gim image buffer height
static __inline__ void sceGimImageSetBufHeight( const SceGimImageHeader *image, unsigned short height_align )
{
	image->height_align = height_align;
}

//-----------------TEXTURE WIDTH-----------------
//get the gim image texture width
static __inline__ int sceGimImageGetTexWidth( const SceGimImageHeader *image, int width )
{
	return sceGimPicturePow2( width );
}

//set the gim image texture width
static __inline__ void sceGimImageSetTexWidth( const SceGimImageHeader *image, unsigned short width )
{
	image->width = width;
}

//-----------------TEXTURE HEIGHT-----------------
//get the gim image texture height
static __inline__ int sceGimImageGetTexHeight( const SceGimImageHeader *image, int height )
{
	return sceGimPicturePow2( height );
}

//set the gim image texture height
static __inline__ void sceGimImageSetTexHeight( const SceGimImageHeader *image, unsigned short height )
{
	image->height= height;
}

//-----------------PLANE MASK-----------------
//get the gim image plane mask
static __inline__ int sceGimImageGetPlaneMask( const SceGimImageHeader *image )
{
	return image->plane_mask;
}

//set the gim image plane mask
static __inline__ void sceGimImageSetPlaneMask( const SceGimImageHeader *image, unsigned int plane_mask )
{
	image->plane_mask = plane_mask;
}

//-----------------LEVEL COUNT-----------------
//get the level count of a gim image
static __inline__ int sceGimImageGetLevelCount( const SceGimImageHeader *image )
{
	return image->level_count;
}

//set the level count of a gim image
static __inline__ void sceGimImageSetLevelCount( const SceGimImageHeader *image , unsigned short level_count )
{
	image->level_count = level_count;
}

//-----------------FRAME COUNT-----------------
//get the number of frames in a gim image
static __inline__ int sceGimImageGetFrameCount( const SceGimImageHeader *image )
{
	return image->frame_count;
}

//set the number of frames in the gim image
static __inline__ void sceGimImageSetFrameCount( const SceGimImageHeader *image, unsigned short frame_count )
{
	image->frame_count = frame_count;
}

//-----------------USER DATA-----------------
//get the image user data
static __inline__ void *sceGimImageGetUserData( const SceGimImageHeader *image )
{
	if ( image->offsets <= image->header_size ) return 0;
	return (char *)image + image->header_size;
}

//return the size of the data block minus the header
static __inline__ void sceGimImageGetUserDataSize( const SceGimImageHeader *image )
{
	return image->offsets - image->header_size;
}

//-----------------PIXELS-----------------
//get the pixel data from gim image
static __inline__ void *sceGimImageGetPixels( const SceGimImageHeader *image, int level, int frame )
{
	void **offsets = (void **)( (char *)image + image->offsets );
	int n_levels = image->level_count;
	int n_frames = image->frame_count;
	if ( level < 0 || level >= n_levels ) return 0;
	frame %= n_frames;
	if ( frame < 0 ) frame += n_frames;
	return offsets[ n_levels * frame + level ];
}

//set the pixel data for gim image
static __inline__ void sceGimImageSetPixels( SceGimImageHeader *image, void **offsets, int n_levels, int n_frames )
{
	(void **)( (char *)image + image->offsets ) = offsets[ n_levels * frame + level ];
	image->level_count = n_levels;
	image->frame_count = n_frames;		
}

//-----------------CHUNK----------------
static __inline__ int sceGimChunkType( SceGimChunk *chunk )
{
	return chunk->type;
}

static __inline__ SceGimChunk *sceGimChunkNext( SceGimChunk *chunk )
{
	return (SceGimChunk *)( (char *)chunk + chunk->next_offs );
}

static __inline__ SceGimChunk *sceGimChunkChild( SceGimChunk *chunk )
{
	return (SceGimChunk *)( (char *)chunk + chunk->child_offs );
}

static __inline__ void *sceGimChunkData( SceGimChunk *chunk )
{
	return (SceGimChunk *)( (char *)chunk + chunk->data_offs );
}

static __inline__ int sceGimChunkSize( SceGimChunk *chunk )
{
	return chunk->next_offs;
}

static __inline__ int sceGimChunkTagSize( SceGimChunk *chunk )
{
	(void)chunk;
	return 16;
}

static __inline__ int sceGimChunkDataSize( SceGimChunk *chunk )
{
	return chunk->child_offs - chunk->data_offs;
}

static __inline__ int sceGimChunkChildSize( SceGimChunk *chunk )
{
	return chunk->next_offs - chunk->child_offs;
}

static __inline__ void *sceGimChunkSkipString( const char *str, int align )
{
	str += strlen( str ) + 1;
	align -= 1;
	return (void *)( ( (int)str + align ) & ~align );
}

