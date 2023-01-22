#include "deck.h"
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    const deck_node_t *n1 = a;
    const deck_node_t *n2 = b;
    int value_cmp = strcmp(n1->card->value, n2->card->value);
    int kind_cmp = n1->card->kind - n2->card->kind;

    if (value_cmp != 0)
        return value_cmp;
    return kind_cmp;
}

void sort_deck(deck_node_t **deck)
{
    deck_node_t *current = *deck;
    size_t size = 52;
    deck_node_t *nodes[52];

    // Copy the nodes to an array
    for (size_t i = 0; i < size; i++)
    {
        nodes[i] = current;
        current = current->next;
    }

    // Sort the array of nodes
    qsort(nodes, size, sizeof(deck_node_t *), cmp);

    // Reconnect the sorted nodes
    *deck = nodes[0];
    nodes[0]->prev = NULL;
