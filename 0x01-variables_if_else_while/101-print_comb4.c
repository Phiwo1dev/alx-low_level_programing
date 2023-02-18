#include <stdio.h>
#include <stdlib.h>
/**
 * main - main block
 * Description: A program that prints different combinations of three digits
 * Return: 0
 */
int main(void)

{
	int c;
	int d;
	int e = 0;

	while (e < 10)
	{
		d = 0;
		while (d < 10)
		{
			c = 0;
			while (c < 10)

				if (c != d && d != e && e < d && d < c)
				{
					putchar('0');
					putchar('0' + d);
					putchar('0' + c);
				}
		}
		c++;
	}
	d++;
e++;

putchar('\n');
return (0);
}
