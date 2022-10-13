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
	push %eax # magic number
    push %ebx # multiboot ptr
    call callConstructors
    call pre_init

	mov $k_initial_stktop, %esp # Returns multiboot ptr in %eax
	push $0
	push $k_initial_stktop	
	push %eax # multiboot ptr
	call kmain

_stop:
    cli
    hlt
    jmp _stop

.section .bss
.space 4096; #4 Kb
kernel_stack:
