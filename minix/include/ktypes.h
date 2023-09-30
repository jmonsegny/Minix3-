#pragma once

#include <arch/i386/types.h>

const uint16_t KMESS_BUF_SIZE = 10000;
const uint8_t PROC_NAME_LEN = 16;

struct KMessage
{
    int _km_next;
    int _km_size;
    char _km_buf[KMESS_BUF_SIZE];
    char _kamess_buf[80*25];
    int _blpos;
};

struct BootImage
{
    int _proc_nr;
    char _proc_name[PROC_NAME_LEN];
    //endpoint _endpoint;
    unsigned long _start_addr;
    unsigned long _len;
};
