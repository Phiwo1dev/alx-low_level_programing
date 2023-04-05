#include "lists.h"

/**
 * sum_listint - returns the sum of data of a listint_t linked list.
 * @head: pointer to the head of a list
 * Return: result of sum
 */
int sum_listint(listint_t *head)

{
	int sum = 0;

	if (!head)
		return (0);
	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
