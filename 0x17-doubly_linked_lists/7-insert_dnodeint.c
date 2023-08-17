#include "lists.h"

static dlistint_t *new_node(int n);

/**
 * insert_dnodeint_at_index - inserts a node at a given index
 * @h: pointer of a pointer to linked list.
 * @idx: where the new node should be added.
 * @n: value to give to new node.
 *
 * Return: a pointer to the add node else NULL if fail.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *new;
	size_t i = 0;

	if (!(*h) && !idx)
		return (*h = new_node(n));
	else if (!idx)
		return (*h = add_dnodeint(h, n));
	node = *h;
	if (node->prev)
		while (node->prev)
			node = node->prev;
	else if (!node->next)
		while (node->prev)
			node = node->prev;

	while (++i < idx && node->next)
	{
		node = node->next;
	}
	if (i < idx)
		return (NULL);
	else if (node)
	{
		n = new_node(n);
		if (!n)
			return (NULL);
		if (n->next)
			node->next->prev = n;
		n->prev = node;
		n->next = node->next;
		node->next = n;
	}
	return (n);
}

/**
 * new_node - a function that creates a new node
 * @n: value to assign to the new node
 *
 * Return: new node.
 */
static dlistint_t *new_node(int n)

{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = new->prev = NULL;

	return (new);
}
