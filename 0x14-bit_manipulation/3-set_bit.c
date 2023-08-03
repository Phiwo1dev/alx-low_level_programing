#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to a number
 * @index: index of the bit to set to 1
 *
 * Return: 1 (Success), -1 for error
 */

int set_bit(unsigned long int *n, unsigned int index)

{
		if (index > 64)
		return (-1);
	if (!((*n >> index) & 1))
	{
		*n += 1 << index;
		return (1);
	}
	return (-1);
}
