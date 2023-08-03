#include "main.h"

/**
 * clear_bit - sets the value ofa bit to 0 at a given index
 * @index: index of the bit to clear
 * @n: pointer to a number
 *
 * Return: 1 (Succes), -1 for error
 */
int clear_bit(unsigned long int *n, unsigned int index)

{
	if (index > 64)
		return (-1);
	if ((*n >> index) & 1)
	{
		*n -= 1 << index;
		return (1);
	}
	return (1);
}
