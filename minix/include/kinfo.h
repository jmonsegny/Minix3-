#pragma once

#include <arch/i386/multiboot.h>
#include <ktypes.h>
#include <com.h>

const uint16_t MAX_MEMMAP = 40;
const uint8_t NR_BOOT_PROCS = NR_TASKS + 11; // fix

struct KInfo
{
    Multiboot _mb;
    MultibootModule _modules[MULTIBOOT_MAX_MODS];
    MultibootMemMap _mem_map[MAX_MEMMAP];
    unsigned long _mem_high_phys;
    int _mmap_size;

    int _mods_with_kernel;
    int _kern_mod;
	
    int _free_pde_star;
    char _param_buf[MULTIBOOT_PARAM_BUF_SIZE];

    KMessage *_kmessages;
    int _do_serial_debug;
    int _serial_debug_baud;
    int _minix_panicing;
    unsigned long _user_sp;
    unsigned long _vir_kern_start;
    unsigned long _bootstrap_start;
    unsigned long _bootstrap_len;
    BootImage _boot_procs[NR_BOOT_PROCS];
    int _nr_procs;
    int _nr_tasks;
    char _release[6];
    char _version[6];
    int _kernel_allocated_bytes;
    int _kernel_allocated_bytes_dynamic;
};
