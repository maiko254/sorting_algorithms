#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *
 * @array: the array to sort
 * @size: number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = array + i;
		for (j = i + 1; j < size; j++)
		{
			min_idx = (array[j] < *min_idx) ? (array + j) : min_idx;
		}

		if ((array + i) != min_idx)
		{
			swap(array + i, min_idx);
			print_array(array, size);
		}
	}
}

/**
 * swap - interchanges the position of two ints in array
 *
 * @a: integer to swap
 * @b: integer to swap
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
