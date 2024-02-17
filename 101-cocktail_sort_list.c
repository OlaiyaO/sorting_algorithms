#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: Pointer to the left node to swap
 * @right: Pointer to the right node to swap
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev != NULL)
		left->prev->next = right;
	else
		*list = right;

	if (right->next != NULL)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;

	print_list(*list);
}

/**
 * forward_pass - Performs a forward pass of the Cocktail Shaker Sort algorithm
 * @list: Pointer to the pointer to the head of the list
 * @swapped: Pointer to the variable indicating whether any swaps were made
 */
void forward_pass(listint_t **list, int *swapped)
{
	listint_t *temp = *list;

	while (temp != NULL && temp->next != NULL)
	{
		if (temp->n > temp->next->n)
		{
			swap_nodes(list, temp, temp->next);
			*swapped = 1;
		}
		else
		{
			temp = temp->next;
		}
	}
}

/**
 * backward_pass - Performs a backward pass of the Cocktail Shaker
 * 		Sort algorithm
 * @list: Pointer to the pointer to the head of the list
 * @swapped: Pointer to the variable indicating whether any swaps were made
 */
void backward_pass(listint_t **list, int *swapped)
{
	listint_t *temp = *list;

	while (temp != NULL && temp->prev != NULL)
	{
		if (temp->prev->n > temp->n)
		{
			swap_nodes(list, temp->prev, temp);
			*swapped = 1;
		}
		else
		{
			temp = temp->prev;
		}
	}
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail Shaker Sort algorithm
 * @list: Pointer to the pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		forward_pass(list, &swapped);
		if (!swapped)
			break;
		backward_pass(list, &swapped);
	}
}
