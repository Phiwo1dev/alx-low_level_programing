#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a linked list
 * @head: first node of the linked list
 * @index: node to fetch from the list
 * Return: pointer to the node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)

{
	unsigned int a = 0;
	listint_t *num = head;

	if (!head)
	return (NULL);
	while (a < index)
	{
	if (!num)
	return (NULL);
	num = num->next;
	a++;
	}
	return (num);
}
