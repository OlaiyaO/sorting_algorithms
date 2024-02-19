#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * get_max - Finds the maximum element in an array
 * @array: The array
 * @size: Number of elements in the array
 * Return: The maximum element in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * count_sort - Sorts an array based on a significant digit
 * 		using counting sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 * @exp: The current significant digit (exponent of 10)
 */
void count_sort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending
 * 		order using Radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	size_t exp;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
