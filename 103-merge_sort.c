#include "sort.h"

/**
 *CopyArray - copy information of an array
 *@array: main array
 *@begin: start position of array
 *@end: final position of array
 *@other: copy of main array
 *
 *Return: Nothing, it's a void function
 */
void CopyArray(int *array, size_t begin, size_t end, int *other)
{
	size_t k;

	for (k = begin; k < end; k++)
		other[k] = array[k];
}

/**
 *TDMerge - Merge array
 *@array: main array
 *@begin: start position of the array
 *@middle: middle position of the array
 *@end: last position of the array
 *@other: copy main array
 *
 *Return: Nothing, it's a void
 */
void TDMerge(int *array, size_t begin, size_t middle, size_t end, int *other)
{
	size_t i = begin, j = middle, k;

	for (k = begin; k < end; k++)
	{
		if (i < middle && (j >= end || array[i] <= array[j]))
		{
			other[k] = array[i];
			i = i + 1;
		}
		else
		{
			other[k] = array[j];
			j = j + 1;
		}
	}
}

/**
 *TopDownSplitMerge - Recursive function that splits and merge the array
 *@other: secontd array
 *@begin: first position of array
 *@end: last position of array
 *@array: main array
 *
 *Return: Nothing, it's a void function
 */
void TopDownSplitMerge(int *other, size_t begin, size_t end, int *array)
{
	size_t middle;
	int i;

	if (end - begin < 2)
		return;
	middle = (end + begin) / 2;
	TopDownSplitMerge(array, begin,  middle, other);
	TopDownSplitMerge(array, middle, end, other);
	printf("Merging...\n");
	printf("[left]: ");
	for (i = begin; i < (int)middle; i++)
	{
		printf("%d", other[i]);
		if (i != (int)middle - 1)
			printf(", ");
	}
	printf("\n");
	printf("[right]: ");
	for (i = middle; i < (int)end; i++)
	{
		printf("%d", other[i]);
		if (i != (int)end - 1)
			printf(", ");
	}
	printf("\n");
	TDMerge(other, begin, middle, end, array);
	printf("[Done]: ");
	for (i = begin; i < (int)end; i++)
	{
		printf("%d", array[i]);
		if (i != (int)end - 1)
			printf(", ");
	}
	printf("\n");
}
/**
 *merge_sort - function that sorts an array based in merge sort method
 *@array: unodered array
 *@size: size of the array
 *
 *Return: Nothing, it's a void
 */
void merge_sort(int *array, size_t size)
{
	int *other = malloc(size * sizeof(int));

	CopyArray(array, 0, size, other);
	TopDownSplitMerge(other, 0, size, array);
	free(other);
}
