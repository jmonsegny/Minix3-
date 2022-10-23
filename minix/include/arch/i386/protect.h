#pragma once

#include <arch/i386/types.h>
#include <arch/i386/gdt.h>
#include <arch/i386/idt.h>
#include <arch/i386/tss.h>
#include <arch/i386/pg.h>

void init_prot( GlobalDescTable& gdt, InterDescTable& idt, tss_s* tss );

uint32_t init_tss( GlobalDescTable& gdt,  tss_s* tss, uint32_t cpu, void* stack );
