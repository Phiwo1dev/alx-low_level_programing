#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - main block
 * Description: Prints all single digit numbers of base 10
 * Starting from 0, followed by new line.
 * Return: Always 0 (Success)
 */
int main(void)

{
	char c = '0';

	while (c <= '9')
	{
		putchar(c);
		c++;
	}

	putchar('\n');
	return (0);
}
