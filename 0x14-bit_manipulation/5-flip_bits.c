#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another.
 * @n: number 1
 * @m: number 2
 *
 * Return: number of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)

{
	unsigned int bits = 0;
	unsigned long int xor = n ^ m;

	while (xor)
	{
	if (xor & 1ul)
		bits++;
	
	xor = xor >> 1;
	}


	return (bits);
}
