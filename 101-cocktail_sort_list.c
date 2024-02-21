#include "sort.h"
#include <stdio.h>

void swap_forward(listint_t **head, listint_t **tail, listint_t **current);
void swap_backward(listint_t **head, listint_t **tail, listint_t **current);
void cocktail_sort_list(listint_t **head);

/**
 * swap_forward - Swap a node in a doubly linked list with the node
 *		ahead of it.
 * @head: A pointer to the head of a doubly linked list.
 * @tail: A pointer to the tail of the doubly linked list.
 * @current: A pointer to the current swapping node.
 */
void swap_forward(listint_t **head, listint_t **tail, listint_t **current)
{
	listint_t *tmp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = tmp;
	else
		*head = tmp;

	tmp->prev = (*current)->prev;
	(*current)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = tmp;
	tmp->next = *current;
	*current = tmp;
}

/**
 * swap_backward - Swap a node in a doubly linked list with the node behind it.
 * @head: A pointer to the head of a doubly linked list.
 * @tail: A pointer to the tail of the doubly linked list.
 * @current: A pointer to the current swapping node.
 */
void swap_backward(listint_t **head, listint_t **tail, listint_t **current)
{
	listint_t *tmp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = tmp;
	else
		*tail = tmp;

	tmp->next = (*current)->next;
	(*current)->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = *current;
	else
		*head = *current;
	(*current)->next = tmp;
	tmp->prev = *current;
	*current = tmp;
}

/**
 * cocktail_sort_list - Sort a doubly linked list of integers in ascending
 *			order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	int sorted = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (sorted == 0)
	{
		sorted = 1;
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_forward(list, &tail, &current);
				print_list((const listint_t *)*list);
				sorted = 0;
			}
		}
		for (current = current->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_backward(list, &tail, &current);
				print_list((const listint_t *)*list);
				sorted = 0;
			}
		}
	}
}

