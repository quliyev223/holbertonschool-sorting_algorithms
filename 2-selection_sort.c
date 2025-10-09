#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 *
 * @array: Pointer to the array to sort
 * @size: NUmber of ellements in the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index_of_min;
	int temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		index_of_min = i;

		/* Find the index of the smallest element in the unsorted part */
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index_of_min])
				index_of_min = j;
		}

		if (index_of_min != i)
		{
			temp = array[i];
			array[i] = array[index_of_min];
			array[index_of_min] = temp;

			/* Print the array after each swap */
			print_array(array, size);
		}
	}
}
