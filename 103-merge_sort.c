#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merge two sorted subarrays into one sorted array.
 * @array: The array to be sorted.
 * @left: Pointer to the left subarray.
 * @left_size: Size of the left subarray.
 * @right: Pointer to the right subarray.
 * @right_size: Size of the right subarray.
 */
void merge(
		int *array,
		int *left,
		size_t left_size,
		int *right,
		size_t right_size
		)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((left_size + right_size) * sizeof(int));

	if (!temp)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}

	while (i < left_size)
		temp[k++] = left[i++];

	while (j < right_size)
		temp[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, left_size + right_size);

	free(temp);
}

/**
 * merge_sort_recursive - Recursively split and merge the array.
 * @array: The array to be sorted.
 * @size: Size of the array.
 */
void merge_sort_recursive(int *array, size_t size)
{
	size_t mid = size / 2;
	int *left = array;
	int *right = array + mid;

	if (size < 2)
		return;

	merge_sort_recursive(left, mid);
	merge_sort_recursive(right, size - mid);
	merge(array, left, mid, right, size - mid);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, size);
}
