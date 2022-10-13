#include <arch/i386/segment.h>
#include <common/types.h>
#include <arch/i386/arch_const.h>

void SegmentDesc::
set_seg_desc( uint32_t base, uint32_t limit, uint8_t flags )
{
	// Base
	_base_lo = (base >>  0) & 0xFFFF;   // 2 3
    _base_md = (base >> 16) & 0xFF;     // 4
	_base_hi = (base >> 24) & 0xFF;     // 7

	// Granularity
	if( limit < 65535 )
		_granularity = 0x40; // 6
	else {
		limit = limit >> 12;
		if( (limit & 0xFFF) != 0xFFF )
			limit--;
		_granularity = 0xC0;
	}
	_granularity |=  (limit >> 16) & 0xF; // 6

	// Limit
	_limit_lo = limit & 0xFFFF;         // 0 1
    _access = flags;                    // 5    
}
	

