#ifndef DECK_H
#define DECK_H

#include <string.h>

/**
 * enum kind_e - Enumeration of card suits
 * @SPADE: Spades
 * @HEART: Hearts
 * @CLUB: Clubs
 * @DIAMOND: Diamonds
 */

typedef enum kind_e
{
	SPADE,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Structure representing a playing card
 * @value: The value of the card (e.g., "Ace", "2", ..., "King")
 * @kind: The suit of the card (SPADE, HEART, CLUB, DIAMOND)
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Structure representing a node in a deck of cards
 * @card: Pointer to the card associated with this node
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
