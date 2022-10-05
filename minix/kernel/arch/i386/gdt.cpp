#include <arch/i386/gdt.h>
#include <common/types.h>
#include <arch/i386/klib.h>

const uint16_t KERN_CS_INDEX = 1;
const uint16_t KERN_DS_INDEX = 2;
const uint16_t USER_CS_INDEX = 3;
const uint16_t USER_DS_INDEX = 4;
const uint16_t LDT_INDEX = 5;

const uint16_t LDT_SELECTOR = LDT_INDEX*8;

const uint8_t INTR_PRIVILEGE = 0;
const uint8_t USER_PRIVILEGE = 3;
const uint8_t DPL_SHIFT = 5;

const uint8_t PRESENT = 0x80;
const uint8_t SEGMENT = 0x10;
const uint8_t EXECUTABLE = 0x08;
const uint8_t READABLE = 0x02;
const uint8_t WRITABLE = 0x02;
const uint8_t ACCESSED = 0x01;

const uint8_t LDT = 2;

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
    _gdt[LDT_INDEX].set_seg_desc( 0, 0, access | LDT );
}

void GlobalDescTable::
load()
{
	x86_lgdt( &_gdt_ptr );
	//x86_lldt( LDT_SELECTOR );
}
