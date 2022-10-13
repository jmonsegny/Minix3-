#pragma once

#include <common/types.h>
#include <kinfo.h>
#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#include <arch/i386/tss.h>
#include <arch/i386/pg.h>
#include <config.h>
#include <ipcconst.h>
#include <proc.h>
#include <priv.h>
#include <call.h>
#include <com.h>
#include <irqhook.h>

class Kernel 
{
public:
	void init( void* mb, void* kernel_stk );

private:
	void read_mb( void* mb );
	void init_sys( void* kernel_stk );
	void init_proc_tbl();
	void set_boot_proc();
	void set_ipc_names();
	void init_system();
	void init_prot();
	uint32_t init_tss( uint32_t cpu, void* stack );
	void init_arch();

	Proc _proc[NR_TASKS + NR_PROCS];
	Priv _priv[NR_SYS_PROCS];
	Priv* _ppriv_addr[NR_SYS_PROCS];
	IrqHook _irq_hooks[NR_IRQ_HOOKS];
	Call* _call_vec[NR_SYS_CALLS];
	char* _ipc_call_names[IPCNO_HIGHEST + 1];

	uint32_t _minix_feature_flags;
	void* _kernel_stk;
	KInfo _kinfo;
	GlobalDescTable _gdt;
	InterDescTable _idt;
    tss_s _tss[MAX_CPUS];	
	Paging _pages;
};
