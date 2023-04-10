#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars.
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)

{
	unsigned int dec_val, num;

	if (!b || !*b)
		return (0);

	dec_val = num = 0;
	while (b[num])
	{
		if (b[num] > 49)
			return (0);
		else if (b[num] == 49)
		{
			dec_val <<= 1;
			dec_val += 1;
		}
		else
			dec_val <<= 1;
		num++;
	}
	return (dec_val);
}
