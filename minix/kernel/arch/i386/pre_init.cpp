#include <common/types.h>
#include <arch/i386/multiboot.h>
#include <arch/i386/pg.h>
#include <arch/i386/direct_tty_utils.h>
#include <arch/i386/utils.h>

// Construtors for C++
typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for( constructor i = start_ctors; i != end_ctors; i++ )
        (*i)();
}

// Preinitialization of Minix 3
extern "C" void* pre_init( void* multiboot_structure, uint32_t magicnumber )
{
	kprintf( "pre_init --- Minix3++\n" );
	kprinthex( (uint32_t)multiboot_structure ); kprintf("\n");
	kprinthex( (uint32_t)magicnumber ); kprintf("\n");

	// Copy multiboot to get mem_upper	
    Multiboot mb;
    kmemcpy( (uint8_t*)(&mb), (uint8_t*)multiboot_structure, sizeof(mb) );

	// Setup the initial paging
	static Paging init_pages;
	
	init_pages.clear();
	init_pages.identity( mb._mem_upper*1024 ); // _mem_upper in Kb -> b
	init_pages.map_kernel();
    init_pages.load();
    init_pages.enable();

	return multiboot_structure;		
}
