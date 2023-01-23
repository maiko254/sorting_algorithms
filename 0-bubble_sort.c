#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array: the array to sort
 * @size: number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	unsigned int swap;
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swap = 1;
				print_array(array, size);
			}
		}

		if (swap == 0)
			break;

	}
}
