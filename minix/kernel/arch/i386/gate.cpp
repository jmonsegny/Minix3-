#include <arch/i386/gate.h>
#include <arch/i386/types.h>
#include <arch/i386/arch_const.h>


void GateDesc::
set_gate_desc( uint32_t offset, uint8_t p_dpl_type )
{
	_offset_lo = offset & 0xFFFF;
	_offset_hi = (offset >> 16) & 0xFFFF;
    _selector = KERN_CS_SELECTOR;
	_p_dpl_type = p_dpl_type;
}

