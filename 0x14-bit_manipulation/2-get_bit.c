#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @index: index of the bit
 * @n: number to search
 *
 * Return: value of the bit
 */
int get_bit(unsigned long int n, unsigned int index)

{
	int bit_val;

	bit_val = ((n >> index) & 1);
	if (index > 63)
		return (-1);
	return (bit_val);
}

