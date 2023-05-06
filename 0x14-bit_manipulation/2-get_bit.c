#include "main.h"

/**
 * get_bit - a function that returns the value of a bit at a given index
 * @index: bit to return
 * @n: number to search
 *
 * Return: bit value
 */
int get_bit(unsigned long int n, unsigned int index)

{
	int bit;

		bit = ((n >> index) & 1);
	if (index > 64)
		return (-1);
	return (bit);
}
