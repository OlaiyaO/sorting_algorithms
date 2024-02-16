#include "sort.h"

void quicksort_recursive(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Helper function for recursive Quick sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Number of elements in the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(array, low, high, size);
		quicksort_recursive(array, low, partition_index - 1, size);
		quicksort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * partition - Partitions the array and returns the pivot index
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	if (i + 1 != high)
		print_array(array, size);
	return (i + 1);
}
