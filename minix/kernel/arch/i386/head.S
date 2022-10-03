.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)
.set MULTIBOOT_VIDEO_MODE_EGA, 1
.set MULTIBOOT_CONSOLE_COLS, 80
.set MULTIBOOT_CONSOLE_LINES, 25

.section .multiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM
    .long 0
    .long 0
    .long 0
    .long 0
    .long 0
    .long MULTIBOOT_VIDEO_MODE_EGA 
    .long MULTIBOOT_CONSOLE_COLS
    .long MULTIBOOT_CONSOLE_LINES
    .long 0


.section .text
.extern pre_init
.extern kmain
.extern k_initial_stktop
.extern callConstructors
.global MINIX

MINIX:
    mov $kernel_stack, %esp
    call callConstructors
    push %eax
    push %ebx
    call pre_init

	mov $k_initial_stktop, %esp
	push $0
	push %eax
	call kmain

_stop:
    cli
    hlt
    jmp _stop

.section .bss
.space 4096; #4 Kb
kernel_stack:
