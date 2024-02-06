#include "search_algos.h"

/**
  * _binary_search - Searches for a value in a sorted array
  *                  of int using binary search
  * @array: Pointer to the first element of the array to search.
  * @left: Starting index of the [sub]array to search.
  * @right: Ending index of the [sub]array to search.
  * @value: Value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Index where the value is located
  */
int _binary_search(int *array, size_t left, size_t right, int value)

{
	size_t l;

	/* Check if the array is NULL */
	if (array == NULL)
		return (-1);

	while (right >= left)
	{
		printf("Searching in array: ");
		for (l = left; l < right; l++)
			printf("%d, ", array[l]);
		printf("%d\n", array[l]);
		l = left + (right - left) / 2;

		if (array[l] == value)
			return (l);
		if (array[l] > value)
			right = l - 1;
		else
			left = l + 1;
	}
	return (-1);
}

/**
  * exponential_search - searches for a value in a sorted array
  *                      of int using exponential search.
  * @array: Pointer to the first element of the array to search.
  * @size: Number of elements in the array.
  * @value: Value to search for
  *
  * Return: If Value is not present or the array is NULL, -1.
  *         Otherwise, Index where the value is located.
  */

int exponential_search(int *array, size_t size, int value)

{
	size_t l = 0, right;

	if (array == NULL)
		return (-1);
	if (array[0] != value)
	{
		for (l = 1; l < size && array[l] <= value; l = l * 2)
			printf("Value checked array[%ld] = [%d]\n", l, array[l]);
	}
	right = l < size ? l : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", l / 2, right);

	return (_binary_search(array, l / 2, right, value));
}
