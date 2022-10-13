#include <arch/i386/protect.h>
#include <arch/i386/arch_const.h>
#include <arch/i386/klib.h>

void init_prot( GlobalDescTable& gdt, InterDescTable& idt, tss_s* tss )
{
	// Setup GDT and IDT    
    gdt.load();
    idt.load();

    // Setup First TSS
    extern char k_boot_stktop; // defined in arch/i386/mpx.S
    init_tss( gdt, tss, 0, &k_boot_stktop );

    // Make processor aware of GDT and IDT
    x86_lldt( LDT_SELECTOR );
    x86_ltr( TSS_SELECTOR ); // Will work with TSS selector
    x86_load_kerncs();
    x86_load_ds( KERN_DS_SELECTOR );
    x86_load_es( KERN_DS_SELECTOR );
    x86_load_fs( KERN_DS_SELECTOR );
    x86_load_gs( KERN_DS_SELECTOR );
    x86_load_ss( KERN_DS_SELECTOR );
}

uint32_t init_tss( GlobalDescTable& gdt,  tss_s* tss, uint32_t cpu, void* stack )
{
    tss_s* t = &tss[cpu];
    uint32_t idx = gdt.init_tss( cpu, t );
    t->_ds = t->_es = t->_fs = t->_gs = t->_ss0 = KERN_DS_SELECTOR;
    t->_cs = KERN_CS_SELECTOR;
    t->_iobase = sizeof(tss_s);

    t->_sp0 = (uint32_t)stack - X86_STACK_TOP_PRESERVED;

    *((uint32_t*)(t->_sp0 + sizeof(uint32_t))) = cpu;

    return idx;
}

