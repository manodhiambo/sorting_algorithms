#include "sort.h"

/**
 * myswapy - swaps values
 *
 * @array: sort data
 * @i: first num
 * @j: second num
 *
 * Return: No Return
 */
void myswapy(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * part - sorts a partition
 *
 * @array: data to sort
 * @left: left
 * @right: right
 * @size: size of data
 *
 * Return: Pivote new
 */
int part(int *array, int left, int right, size_t size)
{
	int i, j, pivot = array[right];

	for (i = left, j = right; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;

		while (array[j] > pivot)
			j--;

		if (i >= j)
			return (i);
		myswapy(array, i, j);
		print_array(array, size);
	}
}

/**
 * myquicksort -  sorts with Quick sort algorithm Lomuto partition scheme
 *
 * @array: data to sort
 * @left: left
 * @right: right
 * @size: size data
 *
 * Return: No Return
 */
void myquicksort(int *array, int left, int right, size_t size)
{
	int pivote;

	if (left < right)
	{
		pivote = part(array, left, right, size);
		myquicksort(array, left, pivote - 1, size);
		myquicksort(array, pivote, right, size);
	}
}

/**
 * quick_sort_hoare -  sorts an array withh Quick sort algorithm Hoare
 *
 * @array: data to sort
 * @size: size of data
 *
 * Return: No Return
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	myquicksort(array, 0, size - 1, size);
}
