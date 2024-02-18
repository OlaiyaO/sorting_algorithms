#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max;
	int *count, *output;
	size_t i;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= (size_t)max; ++i)
		count[i] = 0;
	for (i = 0; i < size; ++i)
		count[array[i]]++;
	for (i = 1; i <= (size_t)max; ++i)
		count[i] += count[i - 1];
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}
	print_array(count, max + 1);
	for (i = 0; i < size; ++i)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < size; ++i)
		array[i] = output[i];
	free(output);
	free(count);
}
