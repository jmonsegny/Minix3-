#pragma once

#include <arch/i386/types.h>

/* 8259A interrupt controller ports. */
const uint8_t INT_CTL      = 0x20;  /* I/O port for interrupt controller */
const uint8_t INT_CTLMASK  = 0x21;  /* setting bits in this port disables ints */
const uint8_t INT2_CTL     = 0xA0;  /* I/O port for second interrupt controller */
const uint8_t INT2_CTLMASK = 0xA1;  /* setting bits in this port disables ints */

const uint8_t IRQ0_VECTOR = 0x50;   /* nice vectors to relocate IRQ0-7 to */
const uint8_t IRQ8_VECTOR = 0x70;   /* no need to move IRQ8-15 */

const uint8_t ICW1_AT             = 0x11; /* edge triggered, cascade, need ICW4 */
const uint8_t ICW1_PC             = 0x13; /* edge triggered, no cascade, need ICW4 */
const uint8_t ICW1_PS             = 0x19; /* level triggered, cascade, need ICW4 */
const uint8_t ICW4_AT_SLAVE       = 0x01; /* not SFNM, not buffered, normal EOI, 8086 */
const uint8_t ICW4_AT_MASTER      = 0x05; /* not SFNM, not buffered, normal EOI, 8086 */
const uint8_t ICW4_PC_SLAVE       = 0x09; /* not SFNM, buffered, normal EOI, 8086 */
const uint8_t ICW4_PC_MASTER      = 0x0D; /* not SFNM, buffered, normal EOI, 8086 */
const uint8_t ICW4_AT_AEOI_SLAVE  = 0x03; /* not SFNM, not buffered, auto EOI, 8086 */
const uint8_t ICW4_AT_AEOI_MASTER = 0x07; /* not SFNM, not buffered, auto EOI, 8086 */
const uint8_t ICW4_PC_AEOI_SLAVE  = 0x0B; /* not SFNM, buffered, auto EOI, 8086 */
const uint8_t ICW4_PC_AEOI_MASTER = 0x0F;/* not SFNM, buffered, auto EOI, 8086 */
 /* Hardware interrupt numbers. */
#ifndef USE_APIC
const uint8_t NR_IRQ_VECTORS = 16;
#else
const uint8_t NR_IRQ_VECTORS = 64;
#endif
const uint8_t CLOCK_IRQ    = 0;
const uint8_t KEYBOARD_IRQ = 1;
const uint8_t CASCADE_IRQ  = 2; /* cascade enable for 2nd AT controller */

int32_t init_intr( int32_t auto_eoi );

