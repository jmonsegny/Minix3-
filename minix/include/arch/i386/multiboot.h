#pragma once

#include <arch/i386/types.h>

class Multiboot
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
    vaddr_t _mi_mods_addr;
} __attribute__((packed));

const uint16_t MULTIBOOT_MAX_MODS = 20;
const uint16_t MULTIBOOT_PARAM_BUF_SIZE = 1024;

struct MultibootModule
{
    uint32_t _mmo_start;
    uint32_t _mmo_end;
    char* _mmo_string;
    uint32_t _mmo_reserved;
};

struct MultibootMemMap
{
    uint32_t _mm_size;
    uint64_t _mm_base_addr;
    uint64_t _mm_length;
    uint32_t _mm_type;
};
