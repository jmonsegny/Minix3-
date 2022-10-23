#include <kernel.h>
#include <arch/i386/types.h>
#include <arch/i386/arch_const.h>
#include <com.h>
#include <arch/i386/direct_tty_utils.h>
#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#include <arch/i386/klib.h>
#include <arch/i386/cpufeature.h>
#include <arch/i386/i8259.h>
#include <arch/i386/protect.h>
#include <arch/i386/multiboot.h>
#include <arch/i386/utils.h>

// Process management objects
static CallDoFork     do_fork;
static CallDoExec     do_exec;
static CallDoClear    do_clear;
static CallDoExit     do_exit;
static CallDoPrivCtl  do_privctl;
static CallDoTrace    do_trace;
static CallDoSetGrant do_setgrant;
static CallDoRunCtl   do_runctl;
static CallDoUpdate   do_update;
static CallDoStateCtl do_statectl;

// Signal handling objects
static CallDoKill     do_kill;
static CallDoGetKSig    do_getksig;
static CallDoEndKSig    do_endksig;
static CallDoSigSend    do_sigsend;
static CallDoSigReturn do_sigreturn;

// Device IO objects
static CallDoIRQCtl do_irqctl;
static CallDoDevIO do_devio;
static CallDoVDevIO do_vdevio;

// Memory management objects
static CallDoMemset do_memset;
static CallDoVMCtl do_vmctl;

// Copying objects
static CallDoUMap do_umap;
static CallDoUMapRemote do_umap_remote;
static CallDoVUMap do_vumap;
static CallDoVirCopy do_vircopy;
static CallDoCopy do_copy;
static CallDoSafeCopyFrom do_safecopy_from;
static CallDoSafeCopyTo do_safecopy_to;
static CallDoVSafeCopy do_vsafecopy;

// Safe memset object
static CallDoSafeMemset do_safememset;

// Clock functionality objects
static CallDoTimes do_times;
static CallDoSetAlarm do_setalarm;
static CallDoSTime do_stime;
static CallDoSetTime do_settime;
static CallDoVTimer do_vtimer;

// System control objects
static CallDoAbort do_abort;
static CallDoGetInfo do_getinfo;
static CallDoDiagCtl do_diagctl;

// Profiling object
static CallDoSProfile do_sprofile;

// i386 specific objects
static CallDoReadBios do_readbios;
static CallDoIOpenTable do_iopentable;
static CallDoSDevIO do_sdevio;

// Machine state switching objects
static CallDoSetmContext do_setmcontext;
static CallDoGetmContext do_getmcontext;

// Scheduling objects
static CallDoSchedule do_schedule;
static CallDoSchedCtl do_schedctl;

void Kernel::
init( void* mb, void* kernel_stk )
{
	// Read multiboot params
	read_mb( mb );

	// Start system
	init_sys( kernel_stk );

	// Initialize processes table
    init_proc_tbl();

	// Set processes in boot image
	set_boot_proc();

	// Set IPC names
	set_ipc_names();

	// Init system
	init_system();
}

void Kernel::
read_mb( void* mb_ptr )
{
	kmemcpy( (uint8_t*)(&_kinfo._mb), (uint8_t*)mb_ptr, sizeof(_kinfo._mb) );
	//TODO: kmemcpy( (uint8_t*)(&_kinfo._kmess), (uint8_t*)

	// Write some multiboot info
	Multiboot &mb = _kinfo._mb;
    kprintf( "flags: " );             kprinthex( mb._flags );             kprintf("\n");
    kprintf( "mem_lower: " );         kprinthex( mb._mem_lower );         kprintf(" Kb\n");
    kprintf( "mem_upper: " );         kprinthex( mb._mem_upper );         kprintf(" Kb\n");
    kprintf( "boot_device_part3: " ); kprinthex( mb._boot_device_part3 ); kprintf("\n");
    kprintf( "boot_device_part2: " ); kprinthex( mb._boot_device_part2 ); kprintf("\n");
    kprintf( "boot_device_part1: " ); kprinthex( mb._boot_device_part1 ); kprintf("\n");
    kprintf( "boot_device_drive: " ); kprinthex( mb._boot_device_drive ); kprintf("\n");
    kprintf( "mods_count: " );        kprinthex( mb._mods_count );        kprintf("\n");
}

void Kernel::
init_sys( void* kernel_stk )
{
	// Kernel stack
	_kernel_stk = kernel_stk;

	// Protection
	init_prot();

	// Interruptions
	init_intr( 0 );

	// Rest of the architecture
	init_arch();
}

// Too i386. Maybe move it to arch/i386?
void Kernel::
init_prot()
{
	// Check if theres is sysenter and syscall support
	if(get_cpu_feature(CPU_I386_SYSENTER))
		_minix_feature_flags |= MKF_I386_INTEL_SYSENTER;
	if(get_cpu_feature(CPU_I386_SYSCALL))
		_minix_feature_flags |= MKF_I386_AMD_SYSCALL;

	// Init protected
	::init_prot( _gdt, _idt, _tss );

	// Remake paging. Needed?
    _pages.clear();
    _pages.identity( _kinfo._mb._mem_upper*1024 ); // _mem_upper in Kb -> b
	_pages.map_kernel(); 
    _pages.load(); 
}

void Kernel::
init_arch()
{
	//TODO
}

void Kernel::
init_proc_tbl()
{
	// Processes table. Only Tasks.
	for( int i = 0; i < NR_TASKS; i++ ) {
		Proc &p = _proc[i];
		p._p_rts_flags = RTS_SLOT_FREE;
		p._p_magic = PMAGIC;
		p._p_nr = -NR_TASKS + i;		
		// TODO p._p_endpoint =
		p._p_scheduler = nullptr;
		p._p_priority = 0;
		p._p_quantum_size_ms = 0;

		// TODO Architecture dependent part
		// reset_proc_arch( p );
	}

	// Privileges table
	for( int i = 0; i < NR_SYS_PROCS; i++ ) {
		Priv &p = _priv[i];
		//p._s_proc_nr = NONE; // Which NONE?
		//p._s_id = i;
		_ppriv_addr[i] = &p;
		//p._s_sig_mgr = NONE;    // Endpoint's NONE?
		//p._s_bak_sig_mgr = NONE; // Endpoint's NONE?
	}

	// TODO:  Per processor table
}

void Kernel::
set_boot_proc()
{
}

void Kernel::
set_ipc_names()
{
	// TODO: Check	
}

void Kernel::
init_system()
{
	// IRQ Hooks
	for( int i = 0; i < NR_IRQ_HOOKS; i++ )
		;//_irq_hooks[i]._proc_nr_e = NONE; 

	// Call vector
	for( int i = 0; i < NR_SYS_CALLS; i++ )
		_call_vec[i] = nullptr;

	// Process management
	_call_vec[SYS_FORK     - KERNEL_CALL] = &do_fork;
	_call_vec[SYS_FORK     - KERNEL_CALL] = &do_fork;
	_call_vec[SYS_EXEC     - KERNEL_CALL] = &do_exec;
	_call_vec[SYS_CLEAR    - KERNEL_CALL] = &do_clear;
	_call_vec[SYS_EXIT     - KERNEL_CALL] = &do_exit;
	_call_vec[SYS_PRIVCTL  - KERNEL_CALL] = &do_privctl;
	_call_vec[SYS_TRACE    - KERNEL_CALL] = &do_trace;
	_call_vec[SYS_SETGRANT - KERNEL_CALL] = &do_setgrant;
	_call_vec[SYS_RUNCTL   - KERNEL_CALL] = &do_runctl;
	_call_vec[SYS_UPDATE   - KERNEL_CALL] = &do_update;
	_call_vec[SYS_STATECTL - KERNEL_CALL] = &do_statectl;

	// Signal handling
	_call_vec[SYS_KILL      - KERNEL_CALL] = &do_kill;
	_call_vec[SYS_GETKSIG   - KERNEL_CALL] = &do_getksig;
	_call_vec[SYS_ENDKSIG   - KERNEL_CALL] = &do_endksig;
	_call_vec[SYS_SIGSEND   - KERNEL_CALL] = &do_sigsend;
	_call_vec[SYS_SIGRETURN - KERNEL_CALL] = &do_sigreturn;

	// Device IO
	_call_vec[SYS_IRQCTL - KERNEL_CALL] = &do_irqctl;
	_call_vec[SYS_DEVIO  - KERNEL_CALL] = &do_devio;
	_call_vec[SYS_VDEVIO - KERNEL_CALL] = &do_vdevio;

	// Memory management
	_call_vec[SYS_MEMSET - KERNEL_CALL] = &do_memset;
	_call_vec[SYS_VMCTL  - KERNEL_CALL] = &do_vmctl;

	// Copying
	_call_vec[SYS_UMAP         - KERNEL_CALL] = &do_umap;
	_call_vec[SYS_UMAP_REMOTE  - KERNEL_CALL] = &do_umap_remote;
	_call_vec[SYS_VUMAP        - KERNEL_CALL] = &do_vumap;
	_call_vec[SYS_VIRCOPY      - KERNEL_CALL] = &do_vircopy;
	_call_vec[SYS_PHYSCOPY     - KERNEL_CALL] = &do_copy;
	_call_vec[SYS_SAFECOPYFROM - KERNEL_CALL] = &do_safecopy_from;
	_call_vec[SYS_SAFECOPYTO   - KERNEL_CALL] = &do_safecopy_to;
	_call_vec[SYS_VSAFECOPY    - KERNEL_CALL] = &do_vsafecopy;

	// Safe memset
	_call_vec[SYS_SAFEMEMSET-KERNEL_CALL] = &do_safememset;

	// Clock functionality
	_call_vec[SYS_TIMES    - KERNEL_CALL] = &do_times;
	_call_vec[SYS_SETALARM - KERNEL_CALL] = &do_setalarm;
	_call_vec[SYS_STIME    - KERNEL_CALL] = &do_stime;
	_call_vec[SYS_SETTIME  - KERNEL_CALL] = &do_settime;
	_call_vec[SYS_VTIMER   - KERNEL_CALL] = &do_vtimer;

	// System control
	_call_vec[SYS_ABORT   - KERNEL_CALL] = &do_abort;
	_call_vec[SYS_GETINFO - KERNEL_CALL] = &do_getinfo;
	_call_vec[SYS_DIAGCTL - KERNEL_CALL] = &do_diagctl;

	// Profiling
	_call_vec[SYS_SPROF - KERNEL_CALL] = &do_sprofile;

	// i386 specific
	_call_vec[SYS_READBIOS   - KERNEL_CALL] = &do_readbios;
	_call_vec[SYS_IOPENTABLE - KERNEL_CALL] = &do_iopentable;
	_call_vec[SYS_SDEVIO     - KERNEL_CALL] = &do_sdevio;

	// Machine state switching
	_call_vec[SYS_SETMCONTEXT - KERNEL_CALL] = &do_setmcontext;
	_call_vec[SYS_GETMCONTEXT - KERNEL_CALL] = &do_getmcontext;

	// Scheduling
	_call_vec[SYS_SCHEDULE - KERNEL_CALL] = &do_schedule;
	_call_vec[SYS_SCHEDCTL - KERNEL_CALL] = &do_schedctl;

	//(*_call_vec[SYS_UPDATE-KERNEL_CALL])(_proc[0]);
}
