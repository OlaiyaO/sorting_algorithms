#include "sort.h"

void _quick_sort(int *array, int lo, int hi, size_t size);
int partition(int *array, int lo, int hi, size_t size);
void swap(int *a, int *b);

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Recursively sorts partitions of the array
 * @array: The array to sort
 * @lo: The low index of the partition
 * @hi: The high index of the partition
 * @size: Number of elements in the array
 */
void _quick_sort(int *array, int lo, int hi, size_t size)
{
	if (lo < hi)
	{
		int p = partition(array, lo, hi, size);

		_quick_sort(array, lo, p - 1, size);
		_quick_sort(array, p + 1, hi, size);
	}
}

/**
 * partition - Partitions the array and returns the pivot index
 * @array: The array to partition
 * @lo: The low index of the partition
 * @hi: The high index of the partition
 * @size: Number of elements in the array
 * Return: The pivot index
 */

int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int j, i = lo - 1;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != hi)
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
