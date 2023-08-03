#include "main.h"

/**
 * get_endianness - a function that checks the endianness.
 *
 * Return: 0 (big endianness), 1 (litte endian)
 */
int get_endianness(void)

{
	unsigned int n = 1;
	char *c = (char *)&n;

	if (*c)
		return (1);

	return (0);
}
