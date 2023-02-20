#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}


/**
 * printKnuthSeq - prints the knuth numbers in stack
 * @knuth: knuth stack sequence
 */
void printKnuthSeq(knuthStack_t *knuth)
{
	knuthStack_t *traversePtr = knuth;

	while (traversePtr != NULL)
	{
		printf("knuth %d\n", traversePtr->knuthNumber);
		traversePtr = traversePtr->next;
	}
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
