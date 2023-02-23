#include "sort.h"

/**
 * swap - function to swap array numbers
 * @a: first number
 * @b: second number
 */
void swap(int *a, int *b)
{
	int tmp = *b;

	*b = *a;

	*a = tmp;
}

/**
 * bubble_sort - sorts an array in ascending order
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, swapped, length = size;

	while (size >= 2)
	{
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap((array + (i - 1)), (array + i));
				print_array(array, length);
				swapped = 1;
			}
		}

		size--;
		if (swapped == 0)
			return;
	}
}
