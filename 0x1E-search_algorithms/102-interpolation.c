#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 *                        of int using the Interpolation search algorithm
 *
 * @array:  Pointer to the first element of the array to search in
 * @size:   Number of elements in array
 * @value:  Value to search for.
 *
 * Return:  Index where value is located
 *          If value is not present in array or if array is NULL,
 *          return -1
 */

int interpolation_search(int *array, size_t size, int value)

{
	size_t start = 0, end = size - 1, pos = 0;

	if (array == NULL)
		return (-1);

	while (((start <= (size - 1)) && (end <= (size - 1))))
	{
		pos = (start + ((value - array[start]) * (end - start))
			/ (array[end] - array[start]));

		if (pos > (size - 1))
		{
			printf("Value checked array[%zu] is out of range\n", pos);
			return (-1);
		}
		printf("Value checked array[%zu] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (value > array[pos])
			start = pos + 1;
		else
			end = pos - 1;
	}
	printf("Value checked array[%zu] is out of range\n", pos);
	return (-1);
}
