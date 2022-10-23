#pragma once

#include <arch/i386/types.h>
#include <arch/i386/arch_const.h>
#include <arch/i386/gate.h>
#include <arch/i386/desctable.h>

struct GateEntry
{
	void (*_gate)(void); // pointer to function
	uint8_t _vec_nr;
	uint8_t _priv;
};

class InterDescTable
{
public:
    InterDescTable();
	void load();
private:
    GateDesc _idt[IDT_SIZE];
    DescTablePtr _idt_ptr;
};
