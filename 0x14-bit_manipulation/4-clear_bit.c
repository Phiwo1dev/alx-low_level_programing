#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0
 * @n: pointer to a number
 * @index: index of the bit to set
 *
 * Return: 1 for success. -1 for error
 */
int clear_bit(unsigned long int *n, unsigned int index)

{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
