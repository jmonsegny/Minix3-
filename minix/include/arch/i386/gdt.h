#pragma once

#include <common/types.h>
#include <arch/i386/arch_const.h>
#include <arch/i386/segment.h>
#include <arch/i386/desctable.h>
#include <arch/i386/tss.h>

class GlobalDescTable
{
public:
	GlobalDescTable();
	void load();
	uint32_t init_tss( uint8_t cpu, tss_s* tss );
private:
	SegmentDesc _gdt[GDT_SIZE];
	DescTablePtr _gdt_ptr;
};
