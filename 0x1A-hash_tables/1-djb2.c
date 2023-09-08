#include "hash_tables.h"

/**
 * hash_djb2 - A hash function implementing the djb2 algorithm.
 * @str: String to hash.
 *
 * Return: Calculated hash.
 */
unsigned long int hash_djb2(const unsigned char *str)

{
	unsigned long int h;
	int i;

	h = 5381;
	while ((i = *str++))
		h = ((h << 5) + h) + i; /* hash * 33 + i */

	return (h);
}
