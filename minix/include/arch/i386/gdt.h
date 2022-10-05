#pragma once

#include <common/types.h>
#include <arch/i386/segment.h>
#include <arch/i386/desctable.h>

const uint32_t MAX_CPUS = 8;
const uint32_t TSS_INDEX = 6;
const uint32_t GDT_SIZE = TSS_INDEX + MAX_CPUS;

class GlobalDescTable
{
public:
	GlobalDescTable();
	void load();
private:
	SegmentDesc _gdt[GDT_SIZE];
	DescTablePtr _gdt_ptr;
};
