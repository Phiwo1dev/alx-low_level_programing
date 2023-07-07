#include "main.h"

/**
 * binary_to_uint - converts a binary number to a unsigned int
 * @b: string containing binary number
 *
 * Return: converted number or 0
 */
unsigned int binary_to_uint(const char *b)

{
	unsigned int dec_val, i;


	if (!b || !*b)
		return (0);

	dec_val = i = 0;
	while (b[i])
	{
		if (b[i] > 49)
			return (0);
		else if (b[i] == 49)
		{
			dec_val <<= 1;
			dec_val += 1;
		}
		else
			dec_val <<= 1;
		i++;
	}
	return (dec_val);
}
