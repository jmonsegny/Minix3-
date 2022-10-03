ENTRY(MINIX)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386:i386)

kern_phys_base = 0x00400000; /* Start at 4Mb */
kern_offset    = 0xF0000000; /* Virtual address - physical address */ 
kern_vir_base  = kern_phys_base + kern_offset; /* Virtual adress */

SECTIONS
{
    . = kern_phys_base;
	kern_virt_base = .;
	.text :
    {
        *(.multiboot)
        *(.text*)
        *(.rodata)
    }

	.data ALIGN(4096) :
    {
        start_ctors = .;
        KEEP(*(.init-array))
        KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)));
        end_ctors = .;

        *(.data)
    }

	.bss ALIGN(4096) :
    {
        *(.bss)
    }

	/DISCARD/ :
    {
        *(.fini_array*)
        *(.comment)
    }
	kern_end = .;

	kern_size = kern_end - kern_phys_base;
}

