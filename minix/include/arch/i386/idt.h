#pragma once

#include <common/types.h>
#include <arch/i386/gate.h>
#include <arch/i386/desctable.h>

const uint16_t IDT_SIZE = 256;

// IRQ NUMBERS
const uint16_t IRQ0 = 0x50 + 0;
const uint16_t IRQ1 = 0x50 + 1;
// ...
const uint16_t IRQ8 = 0x70 + 0;
const uint16_t IRQ9 = 0x70 + 1;
// ...

// EXCEPTION NUMBERS
const uint16_t DIVIDE_ERROR = 0;

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
