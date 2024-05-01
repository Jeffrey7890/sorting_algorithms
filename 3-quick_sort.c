#include "sort.h"
#include <stdio.h>


/**
 * swap - swaps two element in array
 * @a: element 1
 * @b: element 2
 * Return: 0 if a equal b, 1 if a not equals b
 */
int swap(int *a, int *b)
{
	int t = *b;

	if (*a == *b)
		return (0);

	*b = *a;

	*a = t;
	return (1);
}


/**
 * partition - splits the array in-place
 * @array: array to partition
 * @lo: low index in array
 * @hi: high index in array
 * @size: size of array for print_array
 * Return: pivot index
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], i, j;

	i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			if (swap((array + i), (array + j)) == 1)
				print_array(array, size);
		}
	}

	i = i + 1;

	if (swap((array + i), (array + hi)) == 1)
		print_array(array, size);

	return (i);
}


/**
 * _quicksort - lomuto partition scheme, sorting alogrithm
 * this the actual implementaion
 * @array: array to be sorted
 * @lo: low index of array
 * @hi: high index of array
 * @size: size of the array
 */
void _quicksort(int *array, int lo, int hi, size_t size)
{
	int p;

	if ((lo >= hi) || (lo < 0))
	{
		return;
	}

	p = partition(array, lo, hi, size);

	_quicksort(array, lo, p - 1, size);
	_quicksort(array, p + 1, hi, size);
}


/**
 * quick_sort - wrapper function for _quicksort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int lo = 0, hi = (int)(size - 1);

	_quicksort(array, lo, hi, size);
}
