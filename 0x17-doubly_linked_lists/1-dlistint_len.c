#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h: pointer to the head
 *
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)

{
	size_t num = 0;

	if (!h)
		return (0);
	while (h->prev)
		h = h->prev;
	while (h)
	{
		num++;
		h = h->next;
	}
	return (num);
}
