#include "lists.h"

/**
 * pop_listint - deletes the head node and return data
 * @head: pointer to a pointer in the linked list
 *
 * Return: data of the deleted node
 */
int pop_listint(listint_t **head)

{
	int data;
	listint_t *temp;

	if (!(*head) || !head)
		return (0);

	temp = (*head)->next;
	data = (*head)->n;
	free(*head);
	*head = temp;

	return (data);
}
