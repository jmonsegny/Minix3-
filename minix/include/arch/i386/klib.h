#pragma once

extern "C" uint32_t read_cr0();
extern "C" uint32_t read_cr4();
extern "C" void write_cr0( uint32_t );
extern "C" void write_cr3( uint32_t );
extern "C" void write_cr4( uint32_t );
extern "C" void x86_lgdt( void* );
extern "C" void x86_lidt( void* );
extern "C" void x86_lldt( uint32_t );
extern "C" void x86_load_kerncs();
extern "C" void x86_load_ds( uint32_t );
extern "C" void x86_load_es( uint32_t );
extern "C" void x86_load_fs( uint32_t );
extern "C" void x86_load_gs( uint32_t );
extern "C" void x86_load_ss( uint32_t );

