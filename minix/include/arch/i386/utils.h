#include <arch/i386/types.h>

// Kernel memcpy
void kmemcpy( uint8_t* dst, uint8_t* src, uint32_t sz );

// Kernel strncmp
uint32_t kstrncmp( const int8_t* s1, const int8_t* s2, uint32_t n);

