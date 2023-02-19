#include "sort.h"
#include <stdio.h>


/**
 * swap - swaps two int pointers
 * @a: first pointer
 * @b: second pointer
 */
void swap(int *a, int *b)
{
	int tmp = *b;

	*b = *a;

	*a = tmp;
}

/**
 * selection_sort - sorts an arrray of numbers
 * using selection sort algorithm O(n^2)
 * @array: unsorted array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t length = size, i, j;

	int  low_index = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
			if (array[low_index] > array[j])
				low_index = j;

		if (*(array + low_index) < *(array + i))
		{
			swap((array + i), (array + low_index));
			print_array(array, length);
		}
		else
			low_index = i + 1;



	}
}
