#pragma once

#include <common/types.h>

const uint32_t I386_VM_DIR_ENTRIES = 1024;
const uint32_t I386_VM_PT_ENTRIES = 1024;
const uint32_t I386_PAGE_SIZE = 4096;
const uint32_t I386_BIG_PAGE_SIZE = I386_VM_PT_ENTRIES*I386_PAGE_SIZE;

const uint32_t I386_VM_PRESENT = 0x001;
const uint32_t I386_VM_BIGPAGE = 0x080;
const uint32_t I386_VM_USER = 0x004;
const uint32_t I386_VM_WRITE = 0x002;
const uint32_t I386_VM_ADDR_MASK_4MB = 0xFFC00000;
const uint32_t I386_VM_PWT = 0x008;
const uint32_t I386_VM_PCD = 0x010;

const uint32_t I386_CR0_PG = 0x80000000;
const uint32_t I386_CR4_PGE = 0x00000080;
const uint32_t I386_CR4_PSE = 0x00000010;
const uint32_t I386_CR0_WP = 0x00010000;

class Paging
{
public:
    void clear();
    void identity( uint32_t mem_high_phys );
    void map_kernel();
    void load();
    void enable();
 
	uint32_t _pagedir[I386_VM_DIR_ENTRIES] __attribute__((__aligned(4096)));
};
