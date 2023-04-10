#include "main.h"

/**
 * flip_bits - returns the number of bits to flip
 * @n: starting number
 * @m: target number
 *
 * Return: number of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)

{
	unsigned int count = 0;
	unsigned long int num;

	num = n ^ m;

	while (num)
	{
		count += num & 1;
		num >>= 1;
	}
	return (count);
}
