#pragma once

#include <arch/i386/types.h>
#include <arch/i386/stackframe.h>

/* Bits for the runtime flags. A process is runnable iff p_rts_flags == 0. */
const uint32_t RTS_SLOT_FREE = 0x01;	/* process slot is free */

const uint32_t PMAGIC = 0xC0FFEE1;

struct Proc
{
	stackframe_s _p_reg;
	int32_t _p_nr;
	volatile uint32_t _p_rts_flags;

	char _p_priority;
	unsigned int _p_quantum_size_ms;

	struct Proc* _p_scheduler;	

	int32_t _p_magic;
};
