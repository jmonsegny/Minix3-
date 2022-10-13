#include <arch/i386/gdt.h>
#include <common/types.h>
#include <arch/i386/arch_const.h>
#include <arch/i386/klib.h>

GlobalDescTable::
GlobalDescTable()
{
	// GDT pointer
	_gdt_ptr._base = (uint32_t) _gdt;
	_gdt_ptr._limit = sizeof(_gdt) - 1;

	// Zero descriptor invalid
	_gdt[0].set_seg_desc(0,0,0);

	uint8_t access = 0;

	// Kernel CS descriptor
	access = (INTR_PRIVILEGE << DPL_SHIFT) | (PRESENT | SEGMENT | EXECUTABLE | READABLE);
	_gdt[KERN_CS_INDEX].set_seg_desc( 0, 0xFFFFFFFF, access );

	// Kernel DS descriptor
	access = (INTR_PRIVILEGE << DPL_SHIFT) | (PRESENT | SEGMENT | WRITABLE | ACCESSED);
    _gdt[KERN_DS_INDEX].set_seg_desc( 0, 0xFFFFFFFF, access );

	// User CS descriptor
    access = (USER_PRIVILEGE << DPL_SHIFT) | (PRESENT | SEGMENT | EXECUTABLE | READABLE);
    _gdt[USER_CS_INDEX].set_seg_desc( 0, 0xFFFFFFFF, access );

	// User DS descriptor
    access = (USER_PRIVILEGE << DPL_SHIFT) | (PRESENT | SEGMENT | WRITABLE | ACCESSED);
    _gdt[USER_DS_INDEX].set_seg_desc( 0, 0xFFFFFFFF, access );

	// LDT descriptor
    access = PRESENT | LDT;
    _gdt[LDT_INDEX].set_seg_desc( 0, 0, access );
}

void GlobalDescTable::
load()
{
	x86_lgdt( &_gdt_ptr );
}

uint32_t GlobalDescTable::
init_tss( uint8_t cpu, tss_s*  tss )
{
	uint8_t access = PRESENT | (INTR_PRIVILEGE << DPL_SHIFT) | TSS_TYPE;
    _gdt[TSS_INDEX + cpu].set_seg_desc( (uint32_t)tss, sizeof(tss_s), access );

	return (TSS_INDEX + cpu)*DESC_SIZE;
}
