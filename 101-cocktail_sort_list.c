#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: First node to swap
 * @b: Second node to swap
 */
void swap_nodes(listint_t **a, listint_t **b)
{
	listint_t *temp = *a;

	temp->next = (*b)->next;
	if (temp->next != NULL)
		temp->next->prev = temp;
	(*b)->next = temp;

	temp->prev = (*b)->prev;
	if (temp->prev != NULL)
		temp->prev->next = temp;
	(*b)->prev = temp;

	if (temp->prev == NULL)
		*a = *b;

	*b = temp;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using Cocktail Shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;

	do {
		swapped = 0;

		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(&temp, &(temp->next));
				swapped = 1;
				print_list(*list);
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		for (; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n > temp->prev->n)
			{
				swap_nodes(&temp, &(temp->prev));
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}
