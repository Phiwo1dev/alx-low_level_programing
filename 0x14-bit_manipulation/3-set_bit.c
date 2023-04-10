#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: pointer to the number
 * @index: index of the bit starting from 0
 *
 * Return: 1 on success, -1 if it fails
 */
int set_bit(unsigned long int *n, unsigned int index)

{
	if (index > 63)
		return (-1);
	if (!((*n > index) & 1))
	{
		*n += 1 << index;
		return (1);
	}
	return (-1);
}
