#include "lists.h"

/**
 * free_dlistint -a function that frees a linked list.
 * @head: pointer to the linked list.
 */
void free_dlistint(dlistint_t *head)

{
	if (!head)
		return;
	while (head->prev)
		head = head->prev;
	while (head->next)
	{
		head = head->next;
		if (head)
			free(head->prev);
	}
	if (head)
		free(head);
}
