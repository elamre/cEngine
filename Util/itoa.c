/*
 * itoa.c
 *
 * Created: 4/19/2014 11:33:44 AM
 *  Author: Elmar
 */ 

#include "itoa.h"

// Yet, another good itoa implementation
// returns: the length of the number string
int itoa(int value, char *sp, int radix)
{
	char tmp[16];// be careful with the length of the buffer
	char *tp = tmp;
	int i;
	unsigned v = (unsigned)value;

	while (v || tp == tmp)	{
		i = v % radix;
		v /= radix; // v/=radix uses less CPU clocks than v=v/radix does
		if (i < 10)
		*tp++ = i+'0';
		else
		*tp++ = i + 'a' - 10;
	}

	int len = tp - tmp;

	while (tp > tmp)
	*sp++ = *--tp;

	return len;
}