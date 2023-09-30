#include <arch/i386/idt.h>
#include <arch/i386/types.h>
#include <arch/i386/arch_const.h>
#include <arch/i386/mpx.h>
#include <arch/i386/klib.h>

// IRQ table
static struct GateEntry gate_table_pic[] = {
    { hwint00, IRQ0, INTR_PRIVILEGE },  // INTR_PRIVILEGE = 0
    { nullptr, 0, 0 }
};

// Exception table
static struct GateEntry gate_table_excp[] = {
    { divide_error, DIVIDE_ERROR, INTR_PRIVILEGE },
    { nullptr, 0, 0 }
};

InterDescTable::
InterDescTable()
{
    // IDT pointer
    _idt_ptr._base = (uint32_t) _idt;
    _idt_ptr._limit = sizeof(_idt) - 1;

    // Copy IRQ Entries to _idt structure
    for( GateEntry* gtp = gate_table_pic; gtp->_gate; gtp++ ) {
       uint8_t flags = PRESENT | INT_GATE_TYPE | (gtp->_priv << DPL_SHIFT);
        _idt[gtp->_vec_nr].set_gate_desc( (uint32_t)(gtp->_gate), flags  );
    }
	
    // Copy exception entries to _idt structure	
    for( GateEntry* gtp = gate_table_excp; gtp->_gate; gtp++ ) {
        uint8_t flags = PRESENT | INT_GATE_TYPE | (gtp->_priv << DPL_SHIFT);
        _idt[gtp->_vec_nr].set_gate_desc( (uint32_t)(gtp->_gate), flags  );
    }
}

void InterDescTable::
load()
{
    x86_lidt( &_idt_ptr );
}
