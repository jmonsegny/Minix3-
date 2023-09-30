#include <arch/i386/pg.h>
#include <arch/i386/klib.h>
#include <arch/i386/direct_tty_utils.h>

// Variables from the linker script
extern uint8_t kern_phys_base;
extern uint8_t kern_virt_base;
extern uint8_t kern_size;

// Turn them into addresses
static uint32_t kern_phys_start = (uint32_t) &kern_phys_base;
static uint32_t kern_virt_start = (uint32_t) &kern_virt_base;
static uint32_t kern_len = (uint32_t) &kern_size;

// Very important this array is aligned at 4096 bits because cr3 only
// uses first 20 bits to find the page directory.
// The alignement doesn't work always as a class member,
// unless it's static
//static uint32_t pagedir[I386_VM_DIR_ENTRIES] __attribute__((aligned(4096)));
uint32_t Paging::pagedir[I386_VM_DIR_ENTRIES]; //__attribute__((aligned(4096)));

// Make zero the page dir array
void Paging::
clear()
{
    // For all the page directories
    for( int i = 0; i < I386_VM_DIR_ENTRIES; i++ )
        Paging::pagedir[i] = 0;
}

// Fill the page dir array 1-1 with memory.
// Non present memory is flagged as invalid
void Paging::
identity( uint32_t mem_high_phys )
{
    // For all the page directories
    for( int i = 0; i < I386_VM_DIR_ENTRIES; i++ ) {

        // Page is present, big (4MB), user can access, 
        // read and write accesible
        uint32_t flags = I386_VM_PRESENT | I386_VM_BIGPAGE | 
	                 I386_VM_USER | I386_VM_WRITE;

        // Physical start of the page
        uint32_t phys = i * I386_BIG_PAGE_SIZE;

        // If page is bigger than maximum memory, flag 
        // it as write trough and cache disabled
        if( (mem_high_phys & I386_VM_ADDR_MASK_4MB) <= 
	    (phys & I386_VM_ADDR_MASK_4MB) )

            flags |= I386_VM_PWT | I386_VM_PCD;

        // Address in high order bits + flags in low 
        // order bits
        Paging::pagedir[i] = phys | flags;
    }
}

void Paging::
map_kernel()
{
    int off = ((uint32_t)pagedir)%4096;
    if( off )
        off = (4096 - off)/4;

    // Physical position of the kernel
    uint32_t phys = kern_phys_start;
	
    // Index of the page directory pointing to
    // kernel virtual address
    uint32_t pde = kern_virt_start / I386_BIG_PAGE_SIZE;
	
    // Kernel portion mapped
    uint32_t mapped = 0;

    // While kernel is not totally mapped
    while( mapped < kern_len ) {
        // address in high order bits +
        // flags present, big page (4Mb) and readable/writable
        Paging::pagedir[pde] = phys | I386_VM_PRESENT | I386_VM_BIGPAGE | I386_VM_WRITE;
		
        // Update kernel portion already mapped
        mapped += I386_BIG_PAGE_SIZE;		
        phys += I386_BIG_PAGE_SIZE;
        pde++;
    }
}

void Paging::
enable()
{
    // Read cr0 and cr4
    uint32_t cr0 = read_cr0();
    uint32_t cr4 = read_cr4();
	
    // Write cr0 and cr4 clearing PG, PGE and PSE flags
    write_cr0( cr0 & ~I386_CR0_PG );
    write_cr4( cr4 & ~(I386_CR4_PGE | I386_CR4_PSE));

    // Read again cr0 and cr4
    cr0 = read_cr0();
    cr4 = read_cr4();

    // Set 4Mb entries
    cr4 |= I386_CR4_PSE;
    write_cr4( cr4 );

    // Enable paging
    cr0	|= I386_CR0_PG;
    write_cr0( cr0 );

    // Enable global paging
    cr0 |= I386_CR0_WP;
    write_cr0( cr0 );

    // Enable features
    cr4 |= I386_CR4_PGE;
    write_cr4( cr4 );
}

void Paging::
load()
{
    //kprinthex( (uint32_t)Paging::pagedir );
    //kprintf("\n");
    write_cr3( (uint32_t)Paging::pagedir );
}
