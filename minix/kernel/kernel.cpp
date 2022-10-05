#include <kernel.h>
#include <arch/i386/direct_tty_utils.h>
#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#include <arch/i386/klib.h>

const uint8_t CPU_I386_SYSENTER = 16;
const uint8_t CPU_I386_SYSCALL = 17;
const uint32_t MKF_I386_INTEL_SYSENTER = (1L << 0);
const uint32_t MKF_I386_AMD_SYSCALL	 = (1L << 1); 

const uint32_t KERN_DS_SELECTOR = 2*8;
const uint32_t LDT_SELECTOR = 5*8;

void Kernel::
cstart()
{
	prot_init();
}

void Kernel::
prot_init()
{
	// Check if theres is sysenter and syscall support
	// TODO: finish
	if(CPU_I386_SYSENTER)
		_minix_feature_flags |= MKF_I386_INTEL_SYSENTER;
	if(CPU_I386_SYSCALL)
		_minix_feature_flags |= MKF_I386_AMD_SYSCALL;

	// Setup GDT and IDT
	_gdt.load();	
	_idt.load();

	x86_lldt( LDT_SELECTOR );
	x86_load_kerncs();
	x86_load_ds( KERN_DS_SELECTOR );
	x86_load_es( KERN_DS_SELECTOR );
	x86_load_fs( KERN_DS_SELECTOR );
	x86_load_gs( KERN_DS_SELECTOR );
	x86_load_ss( KERN_DS_SELECTOR );
}
