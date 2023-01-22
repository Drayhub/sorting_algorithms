#include <stdlib.h>
#include "deck.h"

/**
 * cmp - Compare two cards based on their value and suit
 * @a: First card
 * @b: Second card
 *
 * Return: Negative value if a < b, positive value if a > b, 0 if a = b
 */
int cmp(const void *a, const void *b)
{
    const deck_node_t *node_a = *(const deck_node_t **)a;
    const deck_node_t *node_b = *(const deck_node_t **)b;
    int value_cmp = strcmp(node_a->card->value, node_b->card->value);

    if (value_cmp != 0)
        return value_cmp;
    return node_a->card->kind - node_b->card->kind;
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the first node of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *current;
    deck_node_t **array;
    size_t size, i;

    if (!deck || !*deck)
        return;
    current = *deck;
    size = 0;
    while (current)
    {
        size++;
        current = current->next;
    }
    array = malloc(sizeof(deck_node_t *) * size);
    if (!array)
        return;
    current = *deck;
    i = 0;
    while (current)
    {
        array[i] = current;
        current = current->next;
        i++;
    }
    qsort(array, size, sizeof(deck_node_t *), cmp);
    for (i = 0; i < size; i++)
    {
        array[i]->prev = i > 0 ? array[i - 1] : NULL;
       
