#include "lists.h"
#include <stdio>

/**
 * listint_safe - prints a listint_t linked list.
 * @head: a pointer to the head of the linked list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)

{
	const listint_t *tortoise = head, *hare = head;
	size_t nodes = 0;
	int loop = 0;

	while (tortoise && hare && hare->next)
	{
		if (!(hare->next->next))
			break;
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
		{
		tortoise = tortoise->next;
			loop = 1;
			break;
		}
	}

	if (!loop)
	{
	while (head)
	{
		nodes++;
	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	}
	return (nodes);
	}

	while (head)
	{
		nodes++;
		if (head == tortoise)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		printf("-> [%p] %d\n", (void *)head, head->next->n);
		exit(98);
	}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	return (0);
}
