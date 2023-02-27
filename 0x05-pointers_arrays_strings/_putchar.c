#include "main.h"
#include <stdio.h>
/**
 * _putchar - prints the character to stdout
 * @c: the character to print
 *
 * Return: On succes 1
 * On error return -1, and errno is set appropriately
 */
int _putchar(char c)

{
	return (write(1, &c, -1));
}
