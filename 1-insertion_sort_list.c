#include "sort.h"


/**
 * swap - swaps two nodes in list
 *
 * @firstNode: the first node to swap
 * @secondNode: second node to swap
 */
void swap(listint_t *firstNode, listint_t *secondNode)
{
	if (firstNode->prev)
		firstNode->prev->next = secondNode;
	if (secondNode->next)
		secondNode->next->prev = firstNode;

	firstNode->next = secondNode->next;
	secondNode->prev = firstNode->prev;

	firstNode->prev = secondNode;
	secondNode->next = firstNode;
}

/**
 * insertion_sort_list - implements the insertion sort algorithm
 *
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *traversePtr, *temporyPtr;

	if (!list || !(*list) || (!(*list)->prev && !(*list)->next))
		return;

	traversePtr = *list;

	while (traversePtr->next)
	{
		if (traversePtr->n > traversePtr->next->n)
		{
			temporyPtr = traversePtr->next;
			swap(traversePtr, traversePtr->next);
			if (!temporyPtr->prev)
				*list = temporyPtr;
			print_list(*list);

			while (temporyPtr->prev && (temporyPtr->prev)->n > temporyPtr->n)
			{
				swap(temporyPtr->prev, temporyPtr);
				if (!temporyPtr->prev)
					*list = temporyPtr;
				print_list(*list);
			}
			traversePtr = temporyPtr;
		}
		traversePtr = traversePtr->next;
	}
}

