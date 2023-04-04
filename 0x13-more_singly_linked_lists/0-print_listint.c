#include"lists.h"

/**
* print_listint - print the int value in each element of a list.
* @h: linked list of type listint_t to be printed
*
* Return: number of elements in a list
*/
size_t print_listint(const listint_t *h)

{
size_t n = 0;

if (!h)
return (0);

while (h)
{
printf("%d\n", h->n);
h = h->next;
n++;
}
return (n);
}
