#include "sort.h"
#include <stdio.h>


void bitonic_sort_recursive(
		int *array,
		size_t size,
		int dir,
		size_t bitonic_size
		);

void bitonic_merge(int *array, size_t size, int dir, size_t bitonic_size);
void swap(int *a, int *b);

/**
 * bitonic_sort - Sorts an array of integers in ascending
 *		order using Bitonic sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	printf("Merging [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);

	bitonic_sort_recursive(array, size, 1, size);

	printf("\n");
}

/**
 * bitonic_sort_recursive - Recursive function to perform Bitonic sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 * @bitonic_size: Size of the subsequence to be sorted
 */
void bitonic_sort_recursive(
		int *array,
		size_t size,
		int dir,
		size_t bitonic_size
		)
{
	if (bitonic_size > 1)
	{
		size_t half = bitonic_size / 2;

		bitonic_sort_recursive(array, half, 1, half);
		bitonic_sort_recursive(array + half, half, 0, half);

		printf("Merging [%lu/%lu] (%s):\n", size, bitonic_size, dir ? "UP" : "DOWN");
		print_array(array, size);

		bitonic_merge(array, size, dir, bitonic_size);
	}
}

/**
 * bitonic_merge - Merges two sorted subsequences in Bitonic manner
 * @array: The array containing the subsequences to be merged
 * @size: Number of elements in the array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 * @bitonic_size: Size of the subsequences to be merged
 */

void bitonic_merge(int *array, size_t size, int dir, size_t bitonic_size)
{
	if (bitonic_size > 1)
	{
		size_t half = bitonic_size / 2;
		size_t i;

		for (i = 0; i + half < size; ++i)
		{
			int j = i + half;

			if (dir ? array[i] > array[j] : array[i] < array[j])
				swap(&array[i], &array[j]);
		}

		printf("Result [%lu/%lu] (%s):\n", half, bitonic_size, dir ? "UP" : "DOWN");
		print_array(array, size);

		bitonic_merge(array, half, dir, half);
		bitonic_merge(array + half, half, dir, half);
	}
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
