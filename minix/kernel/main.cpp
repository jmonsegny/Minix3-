#include <common/types.h>
#include <arch/i386/direct_tty_utils.h>
#include <arch/i386/multiboot.h>
#include <kernel.h>

extern "C" void kmain( void* multiboot, void* kernel_stk )
{
    kprintf( "kmain --- Minix3++\n" );

	static Kernel kernel;
	kernel.init( multiboot, kernel_stk );

	while(1);
}
