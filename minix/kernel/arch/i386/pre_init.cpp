#include <common/types.h>
#include <multiboot/multiboot.h>
#include <arch/i386/pg.h>
#include <arch/i386/direct_tty_utils.h>

// Construtors for C++
typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for( constructor i = start_ctors; i != end_ctors; i++ )
        (*i)();
}

// Cheap memcpy
void memcpy( uint8_t* dst, uint8_t* src, uint32_t sz )
{
	for( uint32_t i = 0; i < sz; i++ )
		dst[i] = src[i];
}


// Preinitialization of Minix 3
extern "C" void pre_init( void* multiboot_structure, uint32_t magicnumber )
{
	printf( "pre_init --- Minix3++\n" );

	// Copy multiboot
    Multiboot mb;
    memcpy( (uint8_t*)(&mb), (uint8_t*)multiboot_structure, sizeof(mb) );

	// Write some multiboot info
    printf( "flags: " ); printhex( mb._flags ); printf("\n");
    printf( "mem_lower: " ); printhex( mb._mem_lower ); printf(" Kb\n");
    printf( "mem_upper: " ); printhex( mb._mem_upper ); printf(" Kb\n");
	printf( "boot_device_part3: " ); printhex( mb._boot_device_part3 ); printf("\n");
	printf( "boot_device_part2: " ); printhex( mb._boot_device_part2 ); printf("\n");
	printf( "boot_device_part1: " ); printhex( mb._boot_device_part1 ); printf("\n");
	printf( "boot_device_drive: " ); printhex( mb._boot_device_drive ); printf("\n");
	printf( "mods_count: " ); printhex( mb._mods_count ); printf("\n");

	// Setup the initial paging
	static Paging init_pages;
	init_pages.clear();
	init_pages.identity( mb._mem_upper*1024 ); // _mem_upper in Kb -> b
	init_pages.map_kernel();
	init_pages.load();
	init_pages.enable();

	// Write some page directories
	for( uint32_t i = 0; i < 10; i++ ) {
		printhex( init_pages._pagedir[i+10] );
		printf( "\n" );
	}		
}
