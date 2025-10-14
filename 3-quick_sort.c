#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Orders a subset of an array of integers according to
 * the Lomuto partition scheme (last element as pivot)
 * @array: The array of integers
 * @size: The  size of the array
 * @low: The starting index of the subset order
 * @high: THe ending index of the subset to order
 *
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;
	above = low;

	for (below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * quicksort_recursive - Implements the quicksort algorithm recursively
 * @array: An array of iintegers tto sort
 * @size: The size of the array
 * @low: The starting index of the array partition to order
 * @high: The ending index of the array partition to order
 */
void quicksort_recursive(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = lomuto_partition(array, size, low, high);
		quicksort_recursive(array, size, low, part - 1);
		quicksort_recursive(array, size, part + 1, high);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the quicksort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;


	quicksort_recursive(array, size, 0, size - 1);
}

