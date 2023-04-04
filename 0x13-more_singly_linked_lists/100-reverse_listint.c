#include "lists.h"

/**
 * reverse_listint - reverse a list.
 * @head: pointer of a pointer to a list.
 *
 * Return: pointer to list.
 */
listint_t *reverse_listint(listint_t **head)

{
	listint_t *temp, *prev;

	if (!head || !(*head))
	{
		return (NULL);
	}

	if (!(*head)->next)
	{
		return (*head);
	}
	temp = *head;
	prev = NULL;
	while (1)
	{
		if (!prev)
		{
			prev = *head;
			temp = temp->next;
			prev->next = NULL;
			*head = prev;
		}
		else
		{
		prev = temp;
		temp = temp->next;
		prev->next = *head;
		if (!temp)
		{
			temp = prev;
			break;
		}
		*head = prev;
		}
	}
	*head = temp;

	return (*head);
}
