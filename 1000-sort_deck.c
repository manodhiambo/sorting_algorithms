#include "deck.h"

/**
 *_strcmp - compare two strings
 *@s1: first string
 *@s2: string to compare
 *
 *Return: 0 if strings are the same, otherwise strings are different
 */
int _strcmp(const char *s1, const char *s2)
{
	int compare, i;

	for (i = 0; s2[i] != '\0'; i++)
	{
		compare = s1[i] - s2[i];
		if (compare != 0)
			break;
	}
	return (compare);
}

/**
 *card_id - return the id of a card value
 *@value: string of value of the card
 *
 *Return: int id of the card
 */
int card_id(const char *value)
{
	int i;
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			  "10", "Jack", "Queen", "King"};
	for (i = 0; i < 13; i++)
	{
		if (_strcmp(value, values[i]) == 0)
			return (i);
	}
	return (0);
}

/**
 *insertion_sort_kind - function that sort a double linke list
 *based in insertion sort
 *@list: double linked list to sort
 *
 *Return: nothing, it's a void function
 */
void insertion_sort_kind(deck_node_t **list)
{
	deck_node_t *cpy_list, *save_prev_node, *test_node;

	cpy_list = *list;
	cpy_list = cpy_list->next;
	while (cpy_list != NULL)
	{
		test_node = cpy_list->prev;
		while (test_node != NULL && test_node->card->kind >
		       cpy_list->card->kind)
		{
			save_prev_node = test_node->prev;
			test_node->next = cpy_list->next;
			test_node->prev = cpy_list;
			if (cpy_list->next != NULL)
				cpy_list->next->prev = test_node;
			cpy_list->next = test_node;
			cpy_list->prev = save_prev_node;
			if (save_prev_node != NULL)
				save_prev_node->next = cpy_list;
			else
				*list = cpy_list;
			test_node = cpy_list->prev;
		}
		cpy_list = cpy_list->next;
	}
}


/**
 *insertion_sort_value - function that sort a double linke list
 *based in insertion sort
 *@list: double linked list to sort
 *
 *Return: nothing, it's a void function
 */
void insertion_sort_value(deck_node_t **list)
{
	deck_node_t *cpy_list, *save_prev_node, *test_node;

	cpy_list = *list;
	cpy_list = cpy_list->next;
	while (cpy_list != NULL)
	{
		test_node = cpy_list->prev;
		while (test_node != NULL && card_id(test_node->card->value) >
		       card_id(cpy_list->card->value))
		{
			save_prev_node = test_node->prev;
			test_node->next = cpy_list->next;
			test_node->prev = cpy_list;
			if (cpy_list->next != NULL)
				cpy_list->next->prev = test_node;
			cpy_list->next = test_node;
			cpy_list->prev = save_prev_node;
			if (save_prev_node != NULL)
				save_prev_node->next = cpy_list;
			else
				*list = cpy_list;
			test_node = cpy_list->prev;
		}
		cpy_list = cpy_list->next;
	}
}


/**
 *sort_deck - main function to sort a deck in a double link_list
 *@deck: double linked list with deck
 *
 *Return: Nothing, it's a void function
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !(*deck))
		return;
	insertion_sort_value(deck);
	insertion_sort_kind(deck);
}
