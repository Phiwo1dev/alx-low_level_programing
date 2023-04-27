#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at index of a
 * listint_t linked list.
 * @head: pointer to the first element in the linked list
 * @index: index of the node to delete
 *
 * Return: 1 (Success), -1 if it fails
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)

{
	unsigned int j;
	listint_t *current, *temp;

	if (!(*head))
		return (-1);
	j = 0;
	temp = NULL;
	current = *head;

	if (!index)
	{
		(*head) = (*head)->next;
		free(current);
		return (1);
	}
	while (current)
	{
		if (j == index)
		{
			temp->next = current->next;
			free(current);
			return (1);
		}
		temp = current;
		current = current->next;
		j++;
	}

	return (-1);
}
