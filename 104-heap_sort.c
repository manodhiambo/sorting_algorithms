#include "sort.h"

/**
 *max - find max value in the heap tree
 *@array: given array
 *@n: larges value of the heap tree
 *@i: starting position to check the heap
 *@j: one position forward i in the array
 *@k: two positions forward i in the arra
 *
 *Return: deepest high value of the current heap tree
 */
int max(int *array, int n, int i, int j, int k)
{
	int m;

	m = i;
	if (j < n && array[j] > array[m])
		m = j;
	if (k < n && (array[k] > array[m]))
		m = k;
	return (m);
}

/**
 *siftDown - re arrange array based in sift down hep method
 *@array: input array
 *@start: final index of heap tree
 *@size: start index of the node in the heap tree
 *@size_a: size of the arrat
 *
 *Return: Nothing, it's a void
 */
void siftDown(int *array, int start, int size, size_t size_a)
{
	int j, save;

	while (1)
	{
		j = max(array, start, size, 2 * size + 1, 2 * size + 2);
		if (j == size)
			break;
		save = array[size];
		array[size] = array[j];
		array[j] = save;
		size = j;
		print_array(array, size_a);
	}
}

/**
 *heap_sort - sort an array based in heap sort method with
 *sift down heap
 *@array: unordered array to sort
 *@size: size of the array
 *
 *Return: Nothing, it's a void function
 */
void heap_sort(int *array, size_t size)
{
	int save, start;

	if (size < 2)
		return;
	for (start = (size - 2) / 2; start >= 0; start--)
		siftDown(array, (int)size, start, size);
	for (start = 0; start < (int)size; start++)
	{
		save = array[(int)size - start - 1];
		array[(int)size - start - 1] = array[0];
		array[0] = save;
		if (array[(int)size - start - 1] != save)
			print_array(array, size);
		siftDown(array, ((int)size - start - 1), 0, size);
	}
}
