#include "sort.h"

/**
 * hoare_partition - crates a partition following the Hoare partition scheme
 *
 * @array: the array to sort
 * @low: the lowest position of the partition
 * @high: the highes position of the partition
 * @size: the size of the array
 *
 * Return: the position to perform recursion
 */

int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, save;

	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j = j - 1;
		} while (array[j] > pivot);
		if (i > j)
		{
			return (j);
		}
		save = array[i];
		array[i] = array[j];
		array[j] = save;
		print_array(array, size);
	}
}

/**
 * quick - performs the recursion of the quicksort algorithm
 *
 * @array: array to sort
 * @low: lowest position
 * @high: highest position
 * @size: size of the array
 */

void quick(int *array, int low, int high, size_t size)
{
	int pos;

	if (low < high)
	{
		pos  = hoare_partition(array, low, high, size);
		quick(array, low, pos, size);
		quick(array, pos  + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sort an array by quicksort method
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: Nothing, it's a void functions
 */

void quick_sort_hoare(int *array, size_t size)
{
	quick(array, 0, (int)size - 1, size);
}
