#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start',
 *              assuming the heaps rooted at its children are valid.
 *
 * @array: The array to be sorted.
 * @start: The starting index of the heap.
 * @end: The ending index of the heap.
 * @size: The size of the array.
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	int tmp;
	size_t swap, child, root = start;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			tmp = array[root];
			array[root] = array[swap];
			array[swap] = tmp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using 
 * 		the Heap sort algorithm
 *
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t start, end;
	int tmp;

	if (array == NULL || size < 2)
		return;

	start = (size - 2) / 2;

	while (start > 0)
	{
		sift_down(array, start, size - 1, size);
		--start;
	}
	sift_down(array, 0, size - 1, size);

	end = size - 1;

	while (end > 0)
	{
		tmp = array[end];
		array[end] = array[0];
		array[0] = tmp;
		print_array(array, size);
		sift_down(array, 0, end - 1, size);
		--end;
	}
}
