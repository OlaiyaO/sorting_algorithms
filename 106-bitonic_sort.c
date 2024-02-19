#include "sort.h"
#include <stdio.h>

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

/**
 * bitonic_merge - Merges two subarrays in a bitonic manner
 * @array: Array to be sorted
 * @start: Starting index of the first subarray
 * @count: Number of elements to be merged
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, int start, int count, int dir)
{
	if (count > 1)
	{
		int i, k = count / 2;
		for (i = start; i < start + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
				swap(&array[i], &array[i + k]);
		}
		bitonic_merge(array, start, k, dir);
		bitonic_merge(array, start + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively performs bitonic sort
 * @array: Array to be sorted
 * @start: Starting index of the subarray
 * @count: Number of elements to be sorted
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, int start, int count, int dir)
{
	int k;
	if (count > 1)
	{
		k = count / 2;
		bitonic_sort_recursive(array, start, k, 1);
		bitonic_sort_recursive(array, start + k, k, 0);
		bitonic_merge(array, start, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending
 * 		order using Bitonic sort
 * @array: Array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}
