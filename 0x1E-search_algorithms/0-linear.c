#include "search_algos.h"

/**
 * linear_search - Searches for a value in a sorted array of
 *                 int using the binary search algorithm
 *
 * @array:  Pointer to the first element of the array to search in
 * @size:   Number of elements in array.
 * @value:  Value to search for.
 *
 * Return: Index where value is located.
 *          If value is not present in array or if array is NULL,
 *          return -1
 */

int linear_search(int *array, size_t size, int value)

{
	size_t l = 0;

	if (array == NULL)
		return (-1);
	for (l = 0; l < size; l++)
	{
		printf("Value checked array[%ld] = [%d]\n", l, array[l]);

		if (value == array[l])
			return (l);
	}
	return (-1);
}
