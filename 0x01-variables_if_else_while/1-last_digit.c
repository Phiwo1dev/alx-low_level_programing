#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * Return: 0 (Success)
 */
int main(void)

{
	int n;
	int num;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	num = n % 10;
	if (num > 5)

	{
		printf("Last digit of %d is int and is greater than 5\n", n);
	}
	else if (num == 0)
	{
		printf("Last digit of %d is int and is 0\n", n);
	}
	else if (num < 6 && num != 0)
	{
		printf("Last digit of %d is int and is less than 6 and not 0\n", n);
	}
	return (0);
}
