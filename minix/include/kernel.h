#pragma once

#include <common/types.h>
#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>

class Kernel 
{
public:
	void cstart();
private:
	void prot_init();

	uint32_t _minix_feature_flags;
	GlobalDescTable _gdt;
	InterDescTable _idt;
};
