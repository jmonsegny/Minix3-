#include <arch/i386/i8259.h>
#include <arch/i386/types.h>
#include <arch/i386/klib.h>

int32_t init_intr( int32_t auto_eoi )
{
    outb( INT_CTL, ICW1_AT );
    outb( INT_CTLMASK, IRQ0_VECTOR );

    outb( INT_CTLMASK, ( 1 << CASCADE_IRQ ) );

    if( auto_eoi )
        outb( INT_CTLMASK, ICW4_AT_AEOI_MASTER );
    else
        outb( INT_CTLMASK, ICW4_AT_MASTER );

    outb( INT_CTLMASK, ~( 1 << CASCADE_IRQ) );
    outb( INT2_CTL, ICW1_AT );
    outb( INT2_CTLMASK, IRQ8_VECTOR );

    outb( INT2_CTLMASK, CASCADE_IRQ );

    if( auto_eoi )
        outb( INT2_CTLMASK, ICW4_AT_AEOI_SLAVE );

        outb( INT2_CTLMASK, ICW4_AT_SLAVE );

    outb( INT2_CTLMASK, ~0 );

    return 0;
}
