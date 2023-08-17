#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a list.
 * @head: pointer to a dlistint linked list.
 *
 * Return: the Sum (int)
 */
int sum_dlistint(dlistint_t *head)

{
	int sum = 0;
	dlistint_t *n;

	if (!head)
		return (0);
	n = head;

	if (!n->next)
		while (n)
		{
			sum += n->n;
			n = n->prev;
		}
	else if (!n->prev)
		while (n)
		{
			sum += n->n;
			n = n->next;
		}
	else
	{
		while (n->prev)
			n = n->prev;
		while (n)
		{
			sum += n->n;
			n = n->next;
		}
	}
	return (sum);
}
