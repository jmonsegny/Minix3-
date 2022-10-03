#pragma once

extern "C" uint32_t read_cr0();
extern "C" uint32_t read_cr4();
extern "C" void write_cr0( uint32_t );
extern "C" void write_cr3( uint32_t );
extern "C" void write_cr4( uint32_t );

