#include "main.h"

/**
 * binary_to_uint - a function that converts binary to unsigned int
 * @b: string to convert to binary
 *
 * Return: converted number
 */
unsigned int binary_to_uint(const char *b)

{
	unsigned int num, a;

	if (!b)
		return (0);
	num = a = 0;
	while (b[a])
	{
		if (b[a] > 49)
			return (0);
		else if (b[a] == 49)
		{
			num <<= 1;
			num += 1;
		}
		else
			num <<= 1;
		a++;
	}
	return (num);
}
