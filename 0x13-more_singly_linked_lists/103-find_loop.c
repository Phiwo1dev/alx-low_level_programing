#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @h: pointer to the head of a list
 *
 * Return: NULL if there is no loop
 * The address of the node where the loop starts
 */
listint_t *find_listint_loop(listint_t *h)

{
	listint_t *tortoise, *hare;

	if (!h)
	return (NULL);

	while (tortoise && hare && hare->next)
	{
	hare = hare->next->next;
	tortoise = tortoise->next;
	if (hare == tortoise)
	{
	tortoise = h;
	while (tortoise != hare)
	{
	tortoise = tortoise->next;
	hare = hare->next;
	}
	return (hare);
	}
	}

	return (NULL);
}
