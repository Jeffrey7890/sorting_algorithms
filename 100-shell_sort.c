#include <stdio.h>
#include "sort.h"

/**
 * _pow - helper power function
 * @number: number to raise
 * @exponent: magnitude to raise number
 * Return: result of power or 1 if exponent is 0
 */
double _pow(double number, double exponent)
{
	double i, result = 1;

	if (exponent == 0)
		return (1);

	for (i = 1; i <= exponent; i++)
		result *= number;
	return (result);
}

/**
 * freeSequence - frees the knuthStack
 * @knuth: head of knuth sequence
 */
void freeSequence(knuthStack_t *knuth)
{
	knuthStack_t *traversePtr = knuth;

	while (knuth != NULL)
	{
		traversePtr = knuth;
		knuth = knuth->next;


		free(traversePtr);
		traversePtr = NULL;
	}
	free(knuth);
}


/**
 * knuthSeqAlgorithm - generated the knuth sequence
 * reverse order
 * @size: size of array
 * Return: a reverse stack sequence
 */
knuthStack_t *knuthSeqAlgorithm(size_t size)
{
	int thirdOfSize, k, knuthSeq, *tmp;

	knuthStack_t *knuthStack = NULL, *knuthNode;

	thirdOfSize = (int)size / 3;
	k = 1;
	knuthSeq = 0;

	while (knuthSeq < thirdOfSize)
	{
		knuthSeq = (_pow(3, k) - 1) / 2;
		knuthNode = malloc(sizeof(*knuthNode));
		if (!knuthNode)
			return (NULL);

		tmp = (int *)&knuthNode->knuthNumber;
		*tmp = knuthSeq;
		knuthNode->next = knuthStack;
		knuthStack = knuthNode;

		/* printf("knuth %d\n", knuthStack->knuthNumber); */
		k += 1;
	}
	return (knuthStack);
}


/**
 * shell_sort - sorts an array with shell sort using knuth sequence
 * @array: array to be sorted
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	knuthStack_t *Sequence, *traverse;

	size_t gap, i, j;

	int temp;

	if (array == NULL)
		return;
	if (size < 2)
		return;

	Sequence = knuthSeqAlgorithm(size);
	traverse = Sequence;

	while (traverse != NULL)
	{
		gap = traverse->knuthNumber;
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
			{
				array[j] = array[j - gap];
			}


			array[j] = temp;
		}
		print_array(array, size);
		traverse = traverse->next;
	}
	freeSequence(Sequence);
}
