GCCPARAMS = -m32 -Iminix/include -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -Wno-write-strings -fno-threadsafe-statics -std=c++11
ASPARAMS = --32
LDPARAMS = -melf_i386

objects = obj/minix/kernel/arch/i386/head.o \
	obj/minix/kernel/arch/i386/mpx.o \
	obj/minix/kernel/arch/i386/pre_init.o \
	obj/minix/kernel/arch/i386/direct_tty_utils.o \
	obj/minix/kernel/arch/i386/utils.o \
	obj/minix/kernel/arch/i386/klib.o \
	obj/minix/kernel/arch/i386/protect.o \
	obj/minix/kernel/arch/i386/cpufeature.o \
	obj/minix/kernel/arch/i386/i8259.o \
	obj/minix/kernel/arch/i386/pg.o \
	obj/minix/kernel/arch/i386/segment.o \
	obj/minix/kernel/arch/i386/gdt.o \
	obj/minix/kernel/arch/i386/gate.o \
	obj/minix/kernel/arch/i386/idt.o \
	obj/minix/kernel/call.o \
	obj/minix/kernel/kernel.o \
	obj/minix/kernel/main.o

obj/%.o: %.cpp
	mkdir -p $(@D)
	g++ $(GCCPARAMS) -o $@ -c $<

obj/%.o: %.S
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

minix3pp.bin: minix/kernel/arch/i386/kernel.lds $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

minix3pp.iso: minix3pp.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/
	echo 'set timeout=0'                  > iso/boot/grub/grub.cfg
	echo 'set default=0'                 >> iso/boot/grub/grub.cfg
	echo ''                              >> iso/boot/grub/grub.cfg
	echo 'menuentry "Minix3plusplus" {'  >> iso/boot/grub/grub.cfg
	echo ' multiboot /boot/minix3pp.bin' >> iso/boot/grub/grub.cfg
	echo ' boot'                         >> iso/boot/grub/grub.cfg
	echo '}'                             >> iso/boot/grub/grub.cfg
	grub2-mkrescue --output=$@ iso
	rm -R iso

run: minix3pp.iso
	(killall VirtualBoxVM && sleep 1) || true
	VirtualBoxVM --startvm "Minix3plusplus" 2> log.txt &

runb: minix3pp.iso
	bochs -f bochsrc.txt -q

runq: minix3pp.iso
	qemu-system-x86_64 -boot d -cdrom minix3pp.iso -m 64 -D qemu_log.txt
	
#install: minix3pp.bin
#   sudo cp $< /boot/minix3pp.bin

.PHONY: clean
clean:
	rm -rf obj minix3pp.bin minix3pp.iso

