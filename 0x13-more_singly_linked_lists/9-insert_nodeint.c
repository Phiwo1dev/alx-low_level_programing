#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the first node in the linked list
 * @idx: index where the new node is to be added
 * @z: value to set to the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)

{
	unsigned int n;
	listint_t *temp, *new;


