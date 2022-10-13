#pragma once

#include <common/types.h>
#include <arch/i386/arch_const.h>

class Paging
{
public:
    void clear();
    void identity( uint32_t mem_high_phys );
    void map_kernel();
    void load();
    void enable();

	// Very important this array is aligned at 4096 bits because cr3 only
	// uses first 20 bits to find the page directory. 	
	alignas(4096) uint32_t _pagedir[I386_VM_DIR_ENTRIES];
};
