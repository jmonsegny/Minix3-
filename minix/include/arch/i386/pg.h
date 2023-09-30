#pragma once

#include <arch/i386/types.h>
#include <arch/i386/arch_const.h>

class Paging
{
public:
    void clear();
    void identity( uint32_t mem_high_phys );
    void map_kernel();
    void load();
    void enable();
private:
    // Very important this array is aligned at 4096 bits because cr3 only
    // uses first 20 bits to find the page directory.
    // The alignement doesn't work always as a class member,
    // unless it's static     
    static uint32_t pagedir[I386_VM_DIR_ENTRIES]__attribute__((aligned(4096)));
};
