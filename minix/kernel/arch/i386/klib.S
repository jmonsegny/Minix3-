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
0:	pop %ebp
	ret
