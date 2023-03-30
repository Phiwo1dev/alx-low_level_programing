#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @b: pointer to the list_t list
 *
 * Return: number of elements in b
 */
size_t list_len(const list_t *b)

{
	size_t n = 0;

	while (b)
	{
	n++;
	b = b->next;
	}

	return (n);
}
