#include "sort.h"

/**
 *counting_sort_radix - sort and array by counting sort method
 *and rearange it starting by the end
 *@array: array of digits
 *@real_array: array of complete values
 *@size: size of the array
 *
 *Return: Nothing, it's a void function
 */

void counting_sort_radix(int *array, int *real_array, size_t size)
{
	size_t k;
	int max_num, i, j;
	int *count_array, *sort_array;

	(void)real_array;
	max_num = array[0];
	sort_array = malloc(size * sizeof(int));
	if (sort_array == NULL)
	{
		free(sort_array);
		return;
	}
	for (k = 0; k < size; k++)
	{
		sort_array[k] = array[k];
		if (array[k] > max_num)
			max_num = array[k];
	}
	count_array = malloc((max_num + 1) * sizeof(int));
	if (count_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = 0; i <= max_num; i++)
		count_array[i] = 0;
	for (k = 0; k < size; k++)
		count_array[array[k]]++;
	for (i = 1; i <= max_num; i++)
		count_array[i] = count_array[i] + count_array[i - 1];
	for (j = (int)size - 1; j >= 0; j--)
	{
		sort_array[count_array[array[j]] - 1] = real_array[j];
		count_array[array[j]] = count_array[array[j]] - 1;
	}
	for (k = 0; k < size; k++)
		real_array[k] = sort_array[k];
	free(count_array);
	free(sort_array);
}

/**
 *radix_sort - sort an array based in radix sort
 *@array: unordered array to sort
 *@size: size of the array
 *
 *Return: Nothing, it's a void
 */

void radix_sort(int *array, size_t size)
{
	int max_num, i, j, n_dig, res_mx_num, mul_f, div_f;
	int *sort_array;

	max_num = array[0];
	mul_f = 10;
	div_f = 1;
	sort_array = malloc(size * sizeof(int));
	if (sort_array ==  NULL)
	{
		free(sort_array);
		return;
	}
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max_num)
			res_mx_num = max_num = array[i];
	}
	for (i = 10, n_dig = 0; res_mx_num != 0; i = i * 10, n_dig++)
	{
		res_mx_num = max_num;
		res_mx_num = res_mx_num / i;
	}
	for (j = 0; j < n_dig; j++)
	{
		for (i = 0; i < (int)size; i++)
			sort_array[i] = (array[i] % mul_f) / div_f;
		counting_sort_radix(sort_array, array, size);
		print_array(array, size);
		mul_f = mul_f * 10;
		div_f = div_f * 10;
	}
	free(sort_array);

}
