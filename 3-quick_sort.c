#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 *
 * @array: the array to sort
 * @size: the number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lom_sort(array, 0, size - 1, size);
}

/**
 * lom_sort - quicksort algorithm by recursion
 * @array: the array to sort
 * @size: the size of the array
 * @lo: left most index element in the array
 * @hi: right most index element in the array
 */
void lom_sort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (hi - lo > 0)
	{
		p = partition(array, lo, hi, size);
		lom_sort(array, lo, p - 1, size);
		lom_sort(array, p + 1, hi, size);
	}
}



/**
 * swap - swaps two integers
 *
 * @a: integer to swap
 * @c: integer to swap
 */
void swap(int *a, int *c)
{
	int t = *a;
	*a = *c;
	*c = t;
}

/**
 * partition - find the partition position
 *
 * @array: the array to partition
 * @lo: left most index  element in the array
 * @hi: right most index element in the array
 * @size: number of elements in the array
 *
 * Return: the partition position
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i, j, *pivot;

	pivot = array + hi;

	for (i = j = lo; j < hi; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}
