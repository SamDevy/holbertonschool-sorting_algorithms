#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @list: pointer to the head of the list
 * @left: first node
 * @right: second node
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

	right->prev = left->prev;
	left->next = right->next;
	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to the head of the list
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

		/* Forward pass */
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
				/* current stays at same node after swap */
			}
			else
				current = current->next;
		}
		end = current;

		if (!swapped)
			break;

		swapped = 0;
		current = end;

		/* Backward pass */
		while (current->prev != start->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
				/* current stays at same node after swap */
			}
			else
				current = current->prev;
		}
		start = current;
	}
}
