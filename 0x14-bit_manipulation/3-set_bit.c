#include "main.h"

/**
 * set_bit -  a function that sets the value of a bit to 1 at a given index.
 * @index - index, starting from 0 of the bit you want to set
 * @n: pointer to a number
 *
 * Return: 1 for success and -1 for error
 */
int set_bit(unsigned long int *n, unsigned int index)

{
	if (index > 63)
		return (-1);
	if (!((*n >> index) & 1))
	{
		*n += 1 << index;
		return (1);
	}
	return (-1);
}
