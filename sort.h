#ifndef __SORT_H__
#define __SORT_H__

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/**
 * knuthStack_s - linked list stack for knuth sequence
 *
 * @knuthNumber: numbers in the sequence
 * @next: next pointer in stack
 */
typedef struct knuthStack_s{
	int knuthNumber;
	struct knuthStack_s *next;
} knuthStack_t;

/* sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);

/* printing functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* helper functions */
void freeSequence(knuthStack_t *knuth);

#endif
