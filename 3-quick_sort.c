#include "sort.h"

/**
 * swap - swaps two integer values
 * @a: first value
 * @b: second value
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomutoPartition - selects the last element of the array as the pivot
 *                   and partitions the array into two subarrays based
 *                   on the pivot index
 * @array: the array to select pivot from
 * @low: left most index of array
 * @high: left most index of array
 * @size: size of the array
 * Return: the selected pivot value
 */
int lomutoPartition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quickSort - sorts an array using quick sort algorithm
 *             by recursively calling itself
 * @array: the array to sort
 * @low: left most index of array
 * @high: right most index of array
 * @size: size of the array
 *
 * Return: void
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int partitionIndex;

	if (low < high)
	{
		partitionIndex = lomutoPartition(array, low, high, size);

		quickSort(array, low, partitionIndex - 1, size);
		quickSort(array, partitionIndex + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using quick sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
