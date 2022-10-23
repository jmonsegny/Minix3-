#pragma once

#include <arch/i386/types.h>

struct tss_s {
	uint32_t _backlink; // 1
	uint32_t _sp0;
	uint32_t _ss0;
	uint32_t _sp1;
	uint32_t _ss1;  // 5
	uint32_t _sp2;
	uint32_t _ss2;
	uint32_t _cr3;
	uint32_t _ip;
	uint32_t _flags; // 10
	uint32_t _ax;
	uint32_t _cx;
	uint32_t _dx;
	uint32_t _bx;
	uint32_t _sp; // 15
	uint32_t _bp;
	uint32_t _si;
	uint32_t _di; 
	uint32_t _es;
	uint32_t _cs; // 20
	uint32_t _ss;
	uint32_t _ds;
	uint32_t _fs;
	uint32_t _gs;
	uint32_t _ldt; // 25
	uint16_t _trap;
	uint16_t _iobase; // 27
} __attribute__((packed));
