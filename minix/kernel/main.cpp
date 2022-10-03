#include <common/types.h>

void printf( int8_t* str );

extern "C" void kmain( void* local_cbi )
{
    printf( "kmain --- Minix3++\n" );

	while(1);
}
