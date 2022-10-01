#include "types.h"

void printf( int8_t* str );

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for( constructor i = start_ctors; i != end_ctors; i++ )
        (*i)();
}

extern "C" void kernelMain( void* multiboot_structure, uint32_t magicnumber )
{
	printf( "Hello World! --- Minix3++\n" );
    printf( "Test\n" );
	
	while(1);
}
