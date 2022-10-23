#pragma once

#include <arch/i386/types.h>

struct stackframe_s
{
	uint16_t _gs; // 1
	uint16_t _fs;
	uint16_t _es;
	uint16_t _ds;
	uint32_t _di; // 5
	uint32_t _si;
	uint32_t _fp;
	uint32_t _bx;
	uint32_t _dx;
	uint32_t _cx; // 10
	uint32_t _retreg;
	uint32_t _pc;
	uint32_t _cs;
	uint32_t _psw;
	uint32_t _sp; // 15
	uint32_t _ss;
};
