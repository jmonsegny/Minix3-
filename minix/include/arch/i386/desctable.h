#pragma once

#include <arch/i386/types.h>

class DescTablePtr
{
public:
    uint16_t _limit;
    uint32_t _base;
} __attribute__((packed));
