.section .text

.global read_cr0
read_cr0:
    push %ebp
    mov %esp, %ebp
    mov %cr0, %eax
    pop %ebp
    ret

.global read_cr4
read_cr4:
    push %ebp
    mov %esp, %ebp
    mov %cr4, %eax
    pop %ebp
    ret

.global write_cr0
write_cr0:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    mov %eax, %cr0
    jmp 0f
0:  pop %ebp
    ret

.global write_cr3
write_cr3:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    mov %eax, %cr3
    jmp 0f
0:  pop %ebp
    ret

.global write_cr4
write_cr4:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    mov %eax, %cr4
    jmp 0f
0:  pop %ebp
    ret

.global x86_lgdt
x86_lgdt:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    lgdt (%eax)
    pop %ebp
    ret

.global x86_lidt
x86_lidt:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    lidtl (%eax)
    pop %ebp
    ret

.global x86_lldt
x86_lldt:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    lldt 8(%ebp)
    pop %ebp
    ret

.global x86_ltr
x86_ltr:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    ltr 8(%ebp)
    pop %ebp
    ret

// KERN_CS_SELECTOR = 1*8
.global x86_load_kerncs
x86_load_kerncs:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    jmp $8, $newcs
newcs:
    pop %ebp
    ret

.global x86_load_ds 
x86_load_ds:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    mov %ax, %ds 
    jmp 0f
0:  pop %ebp
    ret

.global x86_load_es
x86_load_es:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    mov %ax, %es
    jmp 0f
0:  pop %ebp
    ret

.global x86_load_fs
x86_load_fs:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    mov %ax, %fs
    jmp 0f
0:  pop %ebp
    ret

.global x86_load_gs
x86_load_gs:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    mov %ax, %gs
    jmp 0f
0:  pop %ebp
    ret

.global x86_load_ss
x86_load_ss:
    push %ebp
    mov %esp, %ebp
    mov 8(%ebp), %eax
    mov %ax, %ss
    jmp 0f
0:  pop %ebp
    ret


.global cpuid
cpuid:
    push %ebp
    push %ebx
	
    movl 12(%esp), %ebp
    mov (%ebp), %eax
    movl 16(%esp), %ebp
    mov (%ebp), %ebx
    movl 20(%esp), %ebp
    mov (%ebp), %ecx
    movl 24(%esp), %ebp
    mov (%ebp), %edx

    cpuid

    movl 12(%esp), %ebp
    mov %eax, (%ebp)
    movl 16(%esp), %ebp
    mov %ebx, (%ebp)
    movl 20(%esp), %ebp
    mov %ecx, (%ebp)
    movl 24(%esp), %ebp
    mov %edx, (%ebp)

    pop %ebx
    pop %ebp
	
    ret

.global outb
outb:
    push %ebp
    movl %esp, %ebp
    movl 8(%ebp), %edx
    movl 12(%ebp), %eax
    outb %dx
    pop %ebp
    ret
