#include <arch/i386/types.h>
#include <arch/i386/klib.h>
#include <arch/i386/utils.h>

uint32_t get_cpu_feature( uint32_t feature )
{
    uint32_t eax, ebx, ecx, edx;

    // Get cpu vendor string
    eax = 0;
    cpuid( &eax, &ebx, &ecx, &edx );

    // Check Intel or AMD
    uint32_t is_amd = 0, is_intel = 0;
    if( eax > 0 ) {
        // Get processor string
        int8_t vendor[12];
        kmemcpy( (uint8_t*)&(vendor[0]), (uint8_t*)&ebx, sizeof(ebx));
        kmemcpy( (uint8_t*)&(vendor[4]), (uint8_t*)&ecx, sizeof(ecx));
        kmemcpy( (uint8_t*)&(vendor[8]), (uint8_t*)&edx, sizeof(edx));
        if( !kstrncmp( vendor, "GenuineIntel", sizeof(vendor) ) )
            is_intel = 1;
        if( !kstrncmp( vendor, "AuthenticAMD", sizeof(vendor) ) )
            is_amd = 1;
    } else
        return 0;

    // Get cpu model and familly
    eax = 1;
    cpuid( &eax, &ebx, &ecx, &edx );
    uint32_t stepping = eax & 0xF;
    uint32_t model = (eax >> 4) & 0xF;

    if( model == 0xF || model == 0x6 )
        model += ((eax >> 16) & 0xF) << 4;

    uint32_t family = (eax >> 8) & 0xF;

    if( family == 0xF )
        family += (eax >> 20) & 0xFF;

    // Get AMD extra info
    uint32_t ef_eax, ef_ebx, ef_ecx, ef_edx;
    if( is_amd ) {
        ef_eax = 0x80000001;
        cpuid( &ef_eax, &ef_ebx, &ef_ecx, &ef_edx );
    }

	// Get queried info
    /*switch( cpufeature ) {
        
    }*/

    return 0;
}


