#include "sort.h"
#include <stdio.h>



/**
 * swap - swaps two adjacent nodes in doubly linked list
 * @firstNode: pointer to first node
 * @secondNode: pointer to second node to swap
 * Return: int if successful
 */
int swap(listint_t *firstNode, listint_t *secondNode)
{

	if (firstNode->prev)
		firstNode->prev->next = secondNode;
	if (secondNode->next)
		secondNode->next->prev = firstNode;

	firstNode->next = secondNode->next;
	secondNode->prev = firstNode->prev;

	firstNode->prev = secondNode;
	secondNode->next = firstNode;

	return (1);
}

/**
 * cocktail_sort_list - sorts a list using cocktail sort
 * @list: doubly linked list of unordered int
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;

	listint_t *traversePtr;

	if (!list || !(*list) || (!(*list)->prev && !(*list)->next))
		return;

	traversePtr = *list;

	do {
		swapped = 0;
		traversePtr = fowardTrav(list, traversePtr, &swapped);

		if (swapped == 0)
			break;
		traversePtr = backwardTrav(list, traversePtr, &swapped);

	} while (swapped == 1);
}

/**
 * fowardTrav - traverses through list in foward direction
 * @list: list for printing to screen
 * @traversePtr: traversal pointer
 * @swapped: flag to set if swap occurs
 * Return: pointer to listint_t structure
 */
listint_t *fowardTrav(listint_t **list, listint_t *traversePtr, int *swapped)
{
	while (traversePtr != NULL)
	{
		if (traversePtr->n > traversePtr->next->n)
		{
			swap(traversePtr, traversePtr->next);
			*swapped = 1;
			print_list(*list);
		}
		else
			traversePtr = traversePtr->next;
		if (traversePtr->next == NULL)
			break;
	}
	return (traversePtr);
}


/**
 * backwardTrav - traverses through list in foward direction
 * @list: list for printing to screen
 * @traversePtr: traversal pointer
 * @swapped: flag to set if swap occurs
 * Return: pointer to listint_t structure
 */
listint_t *backwardTrav(listint_t **list, listint_t *traversePtr, int *swapped)
{
	while (traversePtr->prev != NULL)
	{
		if (traversePtr->n < traversePtr->prev->n)
		{
			swap(traversePtr->prev, traversePtr);
			*swapped = 1;

			if (traversePtr->prev == NULL)
			{
				*list = traversePtr;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		else
			traversePtr = traversePtr->prev;
	}
	return (traversePtr);
}



