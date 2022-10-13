#pragma once

#include <common/types.h>

struct Mess_u8
{
	uint8_t data[56];
};

struct Mess_u16
{
	uint16_t data[28];
};

#pragma align(16)
struct Message
{
	int m_type;
	union
	{
		Mess_u8 _m_u8;
		Mess_u16 _m_u16;
		uint8_t _size[56];
	};
};
