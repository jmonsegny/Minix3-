#pragma once

#include <arch/i386/types.h>

class GateDesc
{
public:
    void set_gate_desc( uint32_t offset, uint8_t p_dpl_type );
private: 
    uint16_t _offset_lo;
    uint16_t _selector;
    uint8_t _pad;
    uint8_t _p_dpl_type;
    uint16_t _offset_hi;
} __attribute__((packed));
