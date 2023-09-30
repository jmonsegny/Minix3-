#pragma once

#include <arch/i386/types.h>

class SegmentDesc
{
public:
    void set_seg_desc( uint32_t base, uint32_t limit, uint8_t flags );
private:
    uint16_t _limit_lo;
    uint16_t _base_lo;
    uint8_t _base_md;
    uint8_t _access;
    uint8_t _granularity;
    uint8_t _base_hi;
} __attribute__((packed));
