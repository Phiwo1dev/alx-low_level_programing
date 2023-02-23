#include "main.h"
#include <stdio>

/**
 * print_number - prints an integer
 * @n: the integer to print
 * Return: Nothing!
 */

void print_number(int n)

{
	unsigned int k = n;

	if (n < o)
	{
	n *= -1;
	k = n;
	_putchar('-');
	}
	k /= 10;
	if (k != 0)
	print_number(k);
	putchar((unsigned int) n % 10 + '0');
}
