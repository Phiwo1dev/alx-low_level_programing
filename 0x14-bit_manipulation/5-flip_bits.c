#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip.
 * @n: starting number
 * @m: target number
 *
 * Return: number of flipped bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)

{
	unsigned int count = 0;
	unsigned long int current;

	current = n ^ m;

	while (current)
	{
		count += current & 1;
		current >>= 1;
	}
	return (count);
}
