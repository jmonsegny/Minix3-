#include <arch/i386/direct_tty_utils.h>
#include <common/types.h>

void printf( int8_t* str )
{
    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    static uint8_t x = 0, y = 0;

    for( int32_t i = 0; str[i] != '\0'; i++ ) {
        if( str[i] == '\n' ) {
            y++;
            x = 0;
        } else {
            VideoMemory[y*80+x] = (VideoMemory[y*80+x] & 0xFF00) | str[i];
            x++;
        }

        if( x >= 80 ) {
            y++;
            x = 0;
        }

        if( y >= 25 ) {
            for( int j = 0; j < 25*80; j++ )
                VideoMemory[j] = (VideoMemory[i] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}

void printhex( uint32_t num )
{
    static int8_t* keytxt = "00000000\0";
    static int8_t* hex = "0123456789ABCDEF";
    keytxt[0] = hex[(num >> 28) & 0xF];
    keytxt[1] = hex[(num >> 24) & 0xF];
    keytxt[2] = hex[(num >> 20) & 0xF];
    keytxt[3] = hex[(num >> 16) & 0xF];
    keytxt[4] = hex[(num >> 12) & 0xF];
    keytxt[5] = hex[(num >>  8) & 0xF];
    keytxt[6] = hex[(num >>  4) & 0xF];
    keytxt[7] = hex[(num >>  0) & 0xF];
    printf( keytxt );
}

