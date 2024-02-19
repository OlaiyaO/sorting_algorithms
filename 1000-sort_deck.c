#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * compare_cards - Comparison function for qsort
 * @a: Pointer to the first card node
 * @b: Pointer to the second card node
 * Return: -1 if a is less than b, 1 if a is greater than b, 0 otherwise
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = (*(deck_node_t **)a)->card;
	const card_t *card_b = (*(deck_node_t **)b)->card;

	if (card_a->kind != card_b->kind)
		return (card_a->kind - card_b->kind);

	return (strcmp(card_a->value, card_b->value));
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to a pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	int i, count = 0;
	deck_node_t **array;
	deck_node_t *current = *deck;
	
	while (current)
	{
		count++;
		current = current->next;
	}

	array = malloc(count * sizeof(deck_node_t *));
	if (!array)
		return;
	current = *deck;
	for (i = 0; i < count; i++)
	{
		array[i] = current;
		current = current->next;
	}
	qsort(array, count, sizeof(deck_node_t *), compare_cards);

	*deck = array[0];
	for (i = 0; i < count - 1; i++)
	{
		array[i]->next = array[i + 1];
		array[i + 1]->prev = array[i];
	}
	array[count - 1]->next = NULL;
	free(array);
}
