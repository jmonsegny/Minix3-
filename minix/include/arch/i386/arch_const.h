#pragma once

#include <arch/i386/types.h>

const uint32_t MAX_CPUS = 8;
const uint32_t K_STACK_SIZE = 4096;
const uint16_t IDT_SIZE = 256;

// -----------------------------------------
// IRQ NUMBERS
// -----------------------------------------
const uint16_t IRQ0 = 0x50 + 0;
const uint16_t IRQ1 = 0x50 + 1;
// ...
const uint16_t IRQ8 = 0x70 + 0;
const uint16_t IRQ9 = 0x70 + 1;
// ...

// -----------------------------------------
// EXCEPTION NUMBERS
// -----------------------------------------
const uint16_t DIVIDE_ERROR = 0;

// ?

const uint8_t CPU_I386_SYSENTER = 16;
const uint8_t CPU_I386_SYSCALL = 17;
const uint32_t MKF_I386_INTEL_SYSENTER = (1L << 0);
const uint32_t MKF_I386_AMD_SYSCALL  = (1L << 1);

// -------------------------------------------
// GDT indexes and selectors
// -------------------------------------------
const uint16_t KERN_CS_INDEX = 1;
const uint16_t KERN_DS_INDEX = 2;
const uint16_t USER_CS_INDEX = 3;
const uint16_t USER_DS_INDEX = 4;
const uint16_t LDT_INDEX = 5;
const uint16_t TSS_INDEX = 6;

const uint8_t DESC_SIZE = 8;
const uint16_t KERN_CS_SELECTOR = KERN_CS_INDEX*DESC_SIZE;
const uint32_t KERN_DS_SELECTOR = KERN_DS_INDEX*DESC_SIZE;
const uint32_t LDT_SELECTOR = LDT_INDEX*DESC_SIZE;
const uint16_t TSS_SELECTOR = TSS_INDEX*DESC_SIZE;

const uint32_t GDT_SIZE = TSS_INDEX + MAX_CPUS;

// ?

const uint8_t INTR_PRIVILEGE = 0;
const uint8_t USER_PRIVILEGE = 3;
const uint8_t DPL_SHIFT = 5;

// --------------------------------------
// Paging
// --------------------------------------
const uint8_t PRESENT = 0x80;
const uint8_t SEGMENT = 0x10;
const uint8_t EXECUTABLE = 0x08;
const uint8_t READABLE = 0x02;
const uint8_t WRITABLE = 0x02;
const uint8_t ACCESSED = 0x01;

const uint32_t I386_VM_DIR_ENTRIES = 1024;
const uint32_t I386_VM_PT_ENTRIES = 1024;
const uint32_t I386_PAGE_SIZE = 4096;
const uint32_t I386_BIG_PAGE_SIZE = I386_VM_PT_ENTRIES*I386_PAGE_SIZE;

const uint32_t I386_VM_PRESENT = 0x001;
const uint32_t I386_VM_BIGPAGE = 0x080;
const uint32_t I386_VM_USER = 0x004;
const uint32_t I386_VM_WRITE = 0x002;
const uint32_t I386_VM_ADDR_MASK_4MB = 0xFFC00000;
const uint32_t I386_VM_PWT = 0x008;
const uint32_t I386_VM_PCD = 0x010;

const uint32_t I386_CR0_PG = 0x80000000;
const uint32_t I386_CR4_PGE = 0x00000080;
const uint32_t I386_CR4_PSE = 0x00000010;
const uint32_t I386_CR0_WP = 0x00010000;

// ?

const uint8_t LDT = 2;

const uint8_t INT_286_GATE = 6;
const uint8_t AVL_286_TSS = 1;
const uint8_t DESC_386_BIT = 0x08;
const uint8_t INT_GATE_TYPE = INT_286_GATE | DESC_386_BIT;
const uint8_t TSS_TYPE = AVL_286_TSS | DESC_386_BIT;

const uint8_t X86_STACK_TOP_PRESERVED = 2*sizeof(uint32_t);



