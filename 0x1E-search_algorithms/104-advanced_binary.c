#include "search_algos.h"

/**
 * advanced_binary_recursive - searches recursively for a value in a
 *                             sorted array of int using binary search.
 * @array: Pointer to the first element of the [sub]array to search.
 * @left: Starting index of the [sub]array to search.
 * @right: Ending index of the [sub]array to search.
 * @value: Value to search for
 *
 * Return: If the value is not present, -1.
 *         Otherwise, Index where the value is located
 *
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t l;

	if (right < left)
		/* Value not found, return -1 */
		return (-1);

	printf("Searching in array: ");

	for (l = left; l < right; l++)

		printf("%d, ", array[l]);

	printf("%d\n", array[l]);
	l = left + (right - left) / 2;

	if (array[l] == value && (l == left || array[l - 1] != value))

		return (l);

	if (array[l] >= value)

		return (advanced_binary_recursive(array, left, l, value));
		/* Recursively search the right subarray */
	return (advanced_binary_recursive(array, l + 1, right, value));
}

/**
 * advanced_binary - function searches for a value in a sorted array
 *                   of int using advanced binary search
 * @array: Pointer to the first element of the array to search.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, first Index where the value is located
 */

int advanced_binary(int *array, size_t size, int value)

{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
