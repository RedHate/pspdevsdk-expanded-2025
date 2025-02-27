static __inline__ int SCEGMO_CHUNK_TYPE( PspGmoChunk *chunk )
{
	return ( ~SCEGMO_HALF_CHUNK & chunk->type ) ;
}

static __inline__ PspGmoChunk *SCEGMO_CHUNK_NEXT( PspGmoChunk *chunk )
{
	return (PspGmoChunk *)( (char *)chunk + chunk->next_offs ) ;
}

static __inline__ PspGmoChunk *SCEGMO_CHUNK_CHILD( PspGmoChunk *chunk )
{
	if ( SCEGMO_HALF_CHUNK & chunk->type ) return SCEGMO_CHUNK_NEXT( chunk ) ;
	return (PspGmoChunk *)( (char *)chunk + chunk->child_offs ) ;
}

static __inline__ char *SCEGMO_CHUNK_NAME( PspGmoChunk *chunk )
{
	if ( SCEGMO_HALF_CHUNK & chunk->type ) return "" ;
	return (char *)( chunk + 1 ) ;
}

static __inline__ void *SCEGMO_CHUNK_ARGS( PspGmoChunk *chunk )
{
	if ( SCEGMO_HALF_CHUNK & chunk->type ) return (char *)chunk + 8 ;
	return (char *)chunk + chunk->args_offs ;
}

static __inline__ void *SCEGMO_CHUNK_DATA( PspGmoChunk *chunk )
{
	if ( SCEGMO_HALF_CHUNK & chunk->type ) return SCEGMO_CHUNK_ARGS( chunk ) ;
	return (PspGmoChunk *)( (char *)chunk + chunk->data_offs ) ;
}

static __inline__ int SCEGMO_CHUNK_SIZE( PspGmoChunk *chunk )
{
	return chunk->next_offs ;
}

static __inline__ int SCEGMO_CHUNK_TAGSIZE( PspGmoChunk *chunk )
{
	return ( SCEGMO_HALF_CHUNK & chunk->type ) ? 8 : 16 ;
}

static __inline__ int SCEGMO_CHUNK_NAMESIZE( PspGmoChunk *chunk )
{
	if ( SCEGMO_HALF_CHUNK & chunk->type ) return 0 ;
	return chunk->args_offs - 16 ;
}

static __inline__ int SCEGMO_CHUNK_ARGSSIZE( PspGmoChunk *chunk )
{
	if ( SCEGMO_HALF_CHUNK & chunk->type ) return chunk->next_offs - 8 ;
	return chunk->data_offs - chunk->args_offs ;
}

static __inline__ int SCEGMO_CHUNK_DATASIZE( PspGmoChunk *chunk )
{
	if ( SCEGMO_HALF_CHUNK & chunk->type ) return 0 ;
	return chunk->child_offs - chunk->data_offs ;
}

static __inline__ int SCEGMO_CHUNK_CHILDSIZE( PspGmoChunk *chunk )
{
	if ( SCEGMO_HALF_CHUNK & chunk->type ) return 0 ;
	return chunk->next_offs - chunk->child_offs ;
}

static __inline__ void *SCEGMO_CHUNK_SKIPSTRING( const char *str, int align )
{
	str += strlen( str ) + 1 ;
	align -= 1 ;
	return (void *)( ( (int)str + align ) & ~align ) ;
}

static __inline__ PspGmoSubject *sceGmoObserverGetSubject( const PspGmoObserver *observer )
{
	return ( observer == 0 ) ? 0 : observer->m_subject ;
}

static __inline__ PspGmoSubject *sceGmoBaseGetParent( const PspGmoBase *base )
{
	return ( base == 0 ) ? 0 : base->m_parent.m_subject ;
}
