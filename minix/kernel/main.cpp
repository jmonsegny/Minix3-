#include <common/types.h>
#include <arch/i386/direct_tty_utils.h>
#include <kernel.h>

extern "C" void kmain( void* local_cbi )
{
    printf( "kmain --- Minix3++\n" );

	// Copy multiboot
    //Multiboot mb;
    //memcpy( (uint8_t*)(&mb), (uint8_t*)local_cbi, sizeof(mb) );

	static Kernel kernel;//( /*local_cbi*/ ); // Read kinfo and give it to the kernel
	kernel.cstart();

	while(1);
}
