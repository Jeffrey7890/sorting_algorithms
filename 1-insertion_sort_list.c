#include "sort.h"

/**
 * insertion_sort_list - function that sorts a list using insertion sort algo
 *
 * @list: a double linked list to be sorted.
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *new_l, *temp;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	new_l = *list;

	/*Move forward*/
	while (new_l->next)
	{
		if (new_l->n > new_l->next->n)
		{

			temp = new_l->next;
			swap_pos(new_l, new_l->next);
			if (!temp->prev)
				*list = temp;
			print_list(*list);
			/*Move backwards*/
			while (temp->prev && (temp->prev)->n > (temp)->n)
			{
				swap_pos(temp->prev, temp);
				if (!temp->prev)
					*list = temp;
				print_list(*list);
			}
			new_l = temp;
		}
		new_l = new_l->next;
	}
}

/**
 * swap_pos -  function that swaps two double-linked list nodes
 *
 * @A: node to be swapped
 * @B: node to be swapped
 */
void swap_pos(listint_t *A, listint_t *B)
{
	if (A->prev)
		A->prev->next = B;
	if (B->next)
		B->next->prev = A;

	A->next = B->next;
	B->prev = A->prev;

	A->prev = B;
	B->next = A;
}
