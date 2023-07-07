#include "main.h"

/**
 * get_endianness - a function that checks whether endianness is big or small
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)

{
	unsigned int j = 1;
	char *e = (char *)&j;

	if (*e)
		return (1);

	return (0);
}
