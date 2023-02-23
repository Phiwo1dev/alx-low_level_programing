#include "main.h"
#include <stdio.h>

/**
 *
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 * Return: On Success 1 
 * Description: on error print -1, and errno is set appropriately
 */

int _putchar(char c)

{
	return (write(1, &c, 1));
}

