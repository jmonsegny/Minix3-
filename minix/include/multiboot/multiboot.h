#pragma once

#include <common/types.h>

class multiboot
{
public:
	uint32_t _flags;
	uint32_t _mem_lower;
	uint32_t _mem_upper;	
	uint8_t _boot_device_part3;	
	uint8_t _boot_device_part2;
	uint8_t _boot_device_part1;
	uint8_t _boot_device_drive;
	char* _cmdline;
	uint32_t _mods_count;
} __attribute__((packed));
