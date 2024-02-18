#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int left, int mid, int right);
void merge_sort_recursive(int *array, int left, int right);
void merge_sort(int *array, size_t size);

/**
 * merge - Merges two subarrays of array[].
 * @array: The array to be sorted.
 * @left: Starting index of the left subarray.
 * @mid: Middle index of the array.
 * @right: Ending index of the right subarray.
 */
void merge(int *array, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *L = malloc(sizeof(int) * n1);
	int *R = malloc(sizeof(int) * n2);

	if (!L || !R)
	{
		free(L);
		free(R);
		return;
	}

	for (i = 0; i < n1; ++i)
		L[i] = array[left + i];
	for (j = 0; j < n2; ++j)
		R[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			array[k++] = L[i++];
		else
			array[k++] = R[j++];
	}

	while (i < n1)
		array[k++] = L[i++];
	while (j < n2)
		array[k++] = R[j++];

	free(L);
	free(R);
}

/**
 * merge_sort_recursive - Recursive function to perform merge sort.
 * @array: The array to be sorted.
 * @left: Starting index of the subarray.
 * @right: Ending index of the subarray.
 */
void merge_sort_recursive(int *array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		merge_sort_recursive(array, left, mid);
		merge_sort_recursive(array, mid + 1, right);

		printf("Merging...\n");
		printf("[left]: ");
		print_array(array + left, mid - left + 1);
		printf("[right]: ");
		print_array(array + mid + 1, right - mid);

		merge(array, left, mid, right);

		printf("[Done]: ");
		print_array(array + left, right - left + 1);
	}
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

	merge_sort_recursive(array, 0, size - 1);
}
