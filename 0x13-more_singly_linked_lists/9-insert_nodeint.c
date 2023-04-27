#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the first node in the linked list
 * @idx: index where the new node is to be added
 * @n: value of the new node
 *
 * Return: address of the new node, or NULL for failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)

{
	unsigned int j;

	listint_t *node;
	listint_t *pre = *head;

	node = malloc(sizeof(listint_t));
	if (!node || !head)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (idx == 0)
	{
		node->next = *head;
		*head = node;
		return (node);
	}

	for (j = 0; pre && j < idx; j++)
	{
		if (j == idx - 1)
		{
		node->next = pre->next;
		pre->next = node;
		return (node);
	}
	
		else
		pre = pre->next;
	}

	return (NULL);
}
