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
k_initial_stack:
	.space 4096
k_initial_stktop:
.global k_initial_stktop

