#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list.
 * @head: pointer to a pointer of a linked list.
 * @index: index of the node, starting from 0.
 *
 * Return: node or NULL if it doesnt exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	size_t i = 0;
	dlistint_t *node;

	if (!head)
		return (NULL);
	node = head;
	if (node->prev)
		node = node->prev;
	while (i < index && node)
	{
		node = node->next;
		i++;
	}
	return (node);
}
