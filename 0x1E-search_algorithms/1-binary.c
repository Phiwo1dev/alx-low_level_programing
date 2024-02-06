#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of
 *                 integers using the Binary search algorithm.
 *
 * @array:  Pointer to the first element of the array to search in
 * @size:   Number of elements in array
 * @value:  Value to search for.
 *
 * Return:  Index where value is located.
 *          If value is not present in array or if array is NULL,
 *          return -1
 */

int binary_search(int *array, size_t size, int value)

{
	size_t down, up, l, temp;

	down = 0;
	up = size - 1;
	temp = size - 1;
	if (array == NULL)
		return (-1);
	while (down <= up && up <= temp)
	{
		size_t mid;

		mid = (down + up) / 2;
		printf("Searching in array: ");
		for (l = down; l <= up; l++)
		{
			printf("%d", array[l]);
			if (l < up)
				printf(", ");
		}
		printf("\n");
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			down = mid + 1;
		else
			up = mid - 1;
	}
	return (-1);
}
