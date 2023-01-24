#include "sort.h"
int partition(int *array, int lo, int hi, size_t size);
void lom_sort(int *array, int lo, int hi, size_t size);
void swap(int *a, int *b);

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
 * @b: integer to swap
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
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
	int pivot = array[hi];

	int j, i = (lo - 1);

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	if (array[i + 1] > pivot)
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}

	return (i + 1);
}
