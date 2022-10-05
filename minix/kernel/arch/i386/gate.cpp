#include <arch/i386/gate.h>

const uint16_t KERN_CS_INDEX = 1; // Unify with other definition
const uint16_t KERN_CS_SELECTOR = KERN_CS_INDEX*8;

void GateDesc::
set_gate_desc( uint32_t offset, uint8_t p_dpl_type )
{
	_offset_lo = offset & 0xFFFF;
	_offset_hi = (offset >> 16) & 0xFFFF;
    _selector = KERN_CS_SELECTOR;
	_p_dpl_type = p_dpl_type;
}

