#include "lists.h"


static dlistint_t *new_node(const int n);

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: pointer to a pointer of a linked list
 * @n: value to assign to new node
 *
 * Return: a pointer to the newly added node
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node, *new;

	if (*head)
	{
		node = *head;
		while (node->next)
			node = node->next;
		new = new_node(n);
		if (!new)
			return (NULL);
		node->next = new;
		node->next->prev = node;
	}
	else
	{
		node = new_node(n);
		if (!node)
			return (NULL);
		*head = node;
	}
	return (node);
}


/**
 * new_node - creates a new node and assigns a vaule.
 * @n: value to assign to new node
 *
 * Return: a pointer to a new node.
 */
static dlistint_t *new_node(const int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	return (node);
}
