#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swap two adjacent nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: First node
 * @right: Second node (left->next)
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
    if (!left || !right)
        return;

    if (left->prev)
        left->prev->next = right;
    else
        *list = right;

    if (right->next)
        right->next->prev = left;

    left->next = right->next;
    right->prev = left->prev;
    left->prev = right;
    right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *start, *end, *current;

    if (!list || !*list || !(*list)->next)
        return;

    start = *list;
    end = NULL;

    do {
        swapped = 0;
        current = start;

        /* Forward pass */
        while (current->next != end)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                print_list(*list);
                swapped = 1;
                /* After swap, current is still at left node */
            }
            else
                current = current->next;
        }

        /* Update end to last sorted node */
        end = current;

        if (!swapped)
            break;

        swapped = 0;

        /* Backward pass */
        while (current->prev != start->prev && current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                print_list(*list);
                swapped = 1;
                /* After swap, current stays at the right node */
            }
            else
                current = current->prev;
        }

        /* Update start to first sorted node */
        start = current->next;

    } while (swapped);
}
