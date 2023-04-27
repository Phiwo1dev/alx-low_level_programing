#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - prints number of unique nodes of linked list
 * @head: pointer to the head of a list
 *
 * Return: 0 if not a looped list,
 * or number of unique nodes of linked list
 */
size_t looped_listint_len(const listint_t *head)

{
	const listint_t *slow, *fast;
	size_t ele = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow = head->next;
	fast = (head->next)->next;

	while (fast)
	{
	if (slow == fast)
	{
		slow = head;
	while (slow != fast)
	{
		ele++;
		slow = slow->next;
		fast = fast->next;
	}
	slow = slow->next;
	while (slow != fast)
	{
		ele++;
		slow = slow->next;
	}
	return (ele);
	}
	slow = slow->next;
	fast = (fast->next)->next;
	}
	return (0);
}
/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the head of the list
 *
 * Return: length of list.
 */
size_t print_listint_safe(const listint_t *head)

{
	size_t node, pre = 0;

	node = looped_listint_len(head);

	if (node == 0)
	{
	for (; head != NULL; node++)
	{
	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	}
	}
	else
	{
	for (pre  = 0; pre < node; pre++)
	{
	printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}

	printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (node);
}
