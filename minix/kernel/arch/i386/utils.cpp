#include <arch/i386/utils.h>
#include <common/types.h>

// Kernel memcpy
void kmemcpy( uint8_t* dst, uint8_t* src, uint32_t sz )
{
    for( uint32_t i = 0; i < sz; i++ )
        dst[i] = src[i];
}

// Kernel strncmp
uint32_t kstrncmp( const int8_t* s1, const int8_t* s2, uint32_t n)
{
	if( n == 0 )
		return 0;

	for( int i = 0; i < n; i++ ) {
		if( s1[i] == 0 )
			break;
		if( s1[i] != s2[i] )
			return s1[i] - s2[i];
	}

	return 0;
}


