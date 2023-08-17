#include "lists.h"

static dlistint_t *new_node(dlistint_t **head, const int n);

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to a pointer
 * @n: value of the node.
 *
 * Return: pointer to the newly created node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;

	node = new_node(head, n);
	if (!node)
		return (NULL);
	*head = node;
	return (node);
}

/**
 * new_node - a function that creates a new node
 * @head: pointer to a pointer of a dlistint_t list.`
 * @n: value of the new node
 *
 * Return: new none on success, NULL if it fails
 */
static dlistint_t *new_node(dlistint_t **head, const int n)

{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;

	if (*head)
	{
		new->next = *head;
		(*head)->prev = new;
	}

	return (new);
}
