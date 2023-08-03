#include "main.h"

/**
 * binary_to_uint - converts binary to unsigned int
 * @b: string to convert
 *
 * Return: converted string or 0
 */
unsigned int binary_to_uint(const char *b)

{
	unsigned int num, i, dec = 1;

	if (!b || !*b)
		return (0);

	i = 0;
	while (b[i])
	{
		if (b[i] - 48 > 1)
			return (0);
		i++;
	}
	i--;
	num = 0;
	do {
		num += (b[i] - '0') * dec;
		dec *= 2;
	} while (i--);

	return (num);
}
