#include "lists.h"

size_t looped_listint_count(listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_listint_count - counts the number of nodes in a looped list
 * @head: pointer to the head of a list
 *
 * Return: length of list, 0 if the list is not looped
 */
size_t looped_listint_count(listint_t *head)

{
	listint_t *slow, *fast;
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
 * free_listint_safe - frees a listint_t list safely
 * and sets the head to NULL
 * @head: pointer to the head
 *
 * Return: size of freed listint_t list
 */
size_t free_listint_safe(listint_t **head)

{
	listint_t *temp;
	size_t num, idx;

	num = looped_listint_count(*head);

	if (num == 0)
	{
	for (; head != NULL && *head != NULL; num++)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	}
	else
	{
	for (idx = 0; idx < num; idx++)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

		*head = NULL;
	}

	head = NULL;

	return (num);
}
