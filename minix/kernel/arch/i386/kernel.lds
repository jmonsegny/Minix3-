ENTRY(MINIX)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)

kern_phys_base = 0x00400000; /* Start at 4Mb */
kern_offset    = 0x10000000; /* Virtual address - physical address */ 
kern_vir_base  = kern_phys_base + kern_offset; /* Virtual adress */

SECTIONS
{
    . = kern_phys_base;
/*    __k_unpaged__kern_unpaged_start = .;*/
/*    .unpaged_text :*/
	.text :
    {
        *(.multiboot)
        *(.text*)
        *(.rodata)
    }

/*    .unpaged_data ALIGN(4096) :*/
	.data ALIGN(4096) :
    {
        start_ctors = .;
        KEEP(*(.init-array))
        KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)));
        end_ctors = .;

        *(.data)
    }

/*    .unpaged_bss ALIGN(4096) :*/
	.bss ALIGN(4096) :
    {
        *(.bss)
    }

/*	__k_unpaged__kern_unpaged_end = .;

	. += kern_offset;

	. = ALIGN(4096); 
    .text : AT(ADDR(.text)-kern_offset)
	{
		*(.text*)
	} */

	/DISCARD/ :
    {
        *(.fini_array*)
        *(.comment)
    }
}

