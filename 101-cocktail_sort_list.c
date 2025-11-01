#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @list: pointer to head of list
 * @a: first node
 * @b: second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	b->prev = a->prev;
	a->next = b->next;
	b->next = a;
	a->prev = b;
}

/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to head of list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end, *current;
	int swapped;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;
	swapped = 1;

	while (swapped)
	{
		swapped = 0;
		current = start;

		/* forward pass */
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
				/* after swap, current stays at first of the two swapped nodes */
			}
			else
				current = current->next;
		}
		end = current;

		if (!swapped)
			break;

		swapped = 0;
		current = end;

		/* backward pass */
		while (current->prev != start->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
		start = current;
	}
}
