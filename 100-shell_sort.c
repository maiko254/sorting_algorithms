#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *              using the Shell sort algorithm
 *
 * @array: the array to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i;
	int j, k;

	interval = 1;
	while (interval < size / 3)
		interval = 3 * interval + 1;

	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
		{
			k = array[i];
			for (j = i - interval; j >= 0 && k < array[j]; j = j - interval)
				array[j + interval] = array[j];
			array[j + interval] = k;
		}
		interval /= 3;
		print_array(array, size);
	}
}
