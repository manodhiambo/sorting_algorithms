#include "sort.h"

/**
 * shell_sort - Shell sort algorithm
 * @array: unsorted data
 * @size: large of array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t j, gap, n;

	gap = 1;
	if (!array || size < 2)
		return;
	/* Create Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;
	/* Start with the largest gap and work down to a gap of 1 */
	while (gap > 0)
	{
		/* Do a gapped insertion sort for this gap size. */
		/* The first gap elements array[0..gap-1] are already in gapped order */
		/* keep adding one more element until the entire array is gap sorted */
		for (j = gap; j < size; j += 1)
		{
			/* add array[j] to the elements that have been gap sorted */
			/* save array[j] in temp and make a hole at position j */
			tmp = array[j];
			/* shift earlier gap-sorted elements up until the correct */
			/* location for array[j] is found */
			for (n = j; n >= gap && tmp < array[n - gap]; n -= gap)
				array[n] = array[n - gap];
			/* put tmp (the original array[j]) in its correct location */
			array[n] = tmp;
		}
		/* decreasing the interval */
		gap /= 3;
		/*  print the array each time you decrease the interval */
		print_array(array, size);
	}
}
