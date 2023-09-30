#pragma once

#include <arch/i386/types.h>

const uint8_t NR_TASKS = 8; // Move from other places to here

const uint16_t KERNEL_CALL      = 600;

const uint16_t SYS_FORK         = KERNEL_CALL + 0;
const uint16_t SYS_EXEC         = KERNEL_CALL + 1;
const uint16_t SYS_CLEAR        = KERNEL_CALL + 2;
const uint16_t SYS_SCHEDULE     = KERNEL_CALL + 3;
const uint16_t SYS_PRIVCTL      = KERNEL_CALL + 4;
const uint16_t SYS_TRACE        = KERNEL_CALL + 5;
const uint16_t SYS_KILL         = KERNEL_CALL + 6;

const uint16_t SYS_GETKSIG      = KERNEL_CALL + 7;
const uint16_t SYS_ENDKSIG      = KERNEL_CALL + 8;
const uint16_t SYS_SIGSEND      = KERNEL_CALL + 9;
const uint16_t SYS_SIGRETURN    = KERNEL_CALL + 10;

const uint16_t SYS_MEMSET       = KERNEL_CALL + 13;

const uint16_t SYS_UMAP         = KERNEL_CALL + 14;
const uint16_t SYS_VIRCOPY      = KERNEL_CALL + 15;
const uint16_t SYS_PHYSCOPY     = KERNEL_CALL + 16;
const uint16_t SYS_UMAP_REMOTE  = KERNEL_CALL + 17;
const uint16_t SYS_VUMAP        = KERNEL_CALL + 18;

const uint16_t SYS_IRQCTL       = KERNEL_CALL + 19;

const uint16_t SYS_DEVIO        = KERNEL_CALL + 21;
const uint16_t SYS_SDEVIO       = KERNEL_CALL + 22;
const uint16_t SYS_VDEVIO       = KERNEL_CALL + 23;

const uint16_t SYS_SETALARM     = KERNEL_CALL + 24;
const uint16_t SYS_TIMES        = KERNEL_CALL + 25;
const uint16_t SYS_GETINFO      = KERNEL_CALL + 26;
const uint16_t SYS_ABORT        = KERNEL_CALL + 27;

const uint16_t SYS_IOPENTABLE   = KERNEL_CALL + 28;
const uint16_t SYS_SAFECOPYFROM = KERNEL_CALL + 31;
const uint16_t SYS_SAFECOPYTO   = KERNEL_CALL + 32;
const uint16_t SYS_VSAFECOPY    = KERNEL_CALL + 33;
const uint16_t SYS_SETGRANT     = KERNEL_CALL + 34;
const uint16_t SYS_READBIOS     = KERNEL_CALL + 35;
 
const uint16_t SYS_SPROF        = KERNEL_CALL + 36;
 
const uint16_t SYS_STIME        = KERNEL_CALL + 39;
const uint16_t SYS_SETTIME      = KERNEL_CALL + 40;
 
const uint16_t SYS_VMCTL        = KERNEL_CALL + 43;
 
const uint16_t SYS_DIAGCTL      = KERNEL_CALL + 44;
 
const uint16_t SYS_VTIMER       = KERNEL_CALL + 45;
const uint16_t SYS_RUNCTL       = KERNEL_CALL + 46;
const uint16_t SYS_GETMCONTEXT  = KERNEL_CALL + 50;
const uint16_t SYS_SETMCONTEXT  = KERNEL_CALL + 51;
 
const uint16_t SYS_UPDATE       = KERNEL_CALL + 52;
const uint16_t SYS_EXIT	        = KERNEL_CALL + 53;
 
const uint16_t SYS_SCHEDCTL     = KERNEL_CALL + 54;
const uint16_t SYS_STATECTL     = KERNEL_CALL + 55;
 
const uint16_t SYS_SAFEMEMSET   = KERNEL_CALL + 56;
 
const uint16_t SYS_PADCONF      = KERNEL_CALL + 57;
 
// Total 
const uint16_t NR_SYS_CALLS     = 58;
