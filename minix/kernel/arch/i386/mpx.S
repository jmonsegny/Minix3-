//#include <arch/i386/arch_const.h>

//.extern K_STACK_SIZE
//.extern MAX_CPUS

.text

// Hardware interrupts
.macro hwint_master irq
	push %ebp
	movl $0, %ebp
	iret
.endm                  

.global hwint00
hwint00:
	hwint_master 0  

// Exceptions interrupts
.macro EXCEPTION_NO_ERR_CODE vector 
	pushl $0
    push $\vector
.endm

.global divide_error
divide_error:
	EXCEPTION_NO_ERR_CODE 0        

.section .bss
// How to use const K_STACK_SIZE here?
// Initial stack
k_initial_stack:
.space 4096
k_initial_stktop:
.global k_initial_stktop

// Booting stack
k_boot_stack:
.space 4096
k_boot_stktop:
.global k_boot_stktop

// A stack per processor
k_stacks_start:
.global k_stacks_start
	.space 2*(4096*8)
k_stacks_end:
.global k_stacks_end

