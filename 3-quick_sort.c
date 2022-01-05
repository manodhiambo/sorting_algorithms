#include "sort.h"

/**
 * myswap - swaps two values
 *
 * @array: data sort input
 * @firts: first
 * @second: second
 * @size: size
 *
 * Return: No Return
 */
void myswap(int *array, int firts, int second, int size)
{
	int tmp;

	if (array[firts] != array[second])
	{
		tmp = array[firts];
		array[firts] = array[second];
		array[second] = tmp;
		print_array(array, size);
	}
}

/**
 * part - part to a pivot
 *
 * @array: data sort input
 * @left: left
 * @right: right
 * @size: size input
 *
 * Return: New pivote
 */
int part(int *array, int left, int right, size_t size)
{
	int i = left, j, pivot  = array[right];

	for (j = left; j <= right; j++)
	{
		if (array[j] < pivot)
		{
			myswap(array, i, j, size);
			i++;
		}
	}
	myswap(array, i, right, size);

	return (i);
}

/**
 * myquicksort -  quick sort algorithm
 *
 * @array: data to sort
 * @left: left pivote
 * @right: right pivote
 * @size: size input
 * Return: No Return
 */
void myquicksort(int *array, int left, int right, size_t size)
{
	int pivote;

	if (left < right)
	{
		pivote = part(array, left, right, size);
		myquicksort(array, left, pivote - 1, size);
		myquicksort(array, pivote + 1, right, size);
	}
}

/**
 * quick_sort -  quick sort algorithm
 *
 * @array: sort data
 * @size: size input
 *
 * Return: No Return
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	myquicksort(array, 0, size - 1, size);
}
