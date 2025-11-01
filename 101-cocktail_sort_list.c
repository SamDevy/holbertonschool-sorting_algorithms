#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @left: pointer to the first node
 * @right: pointer to the second node
 * @list: pointer to the head of the list
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
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
 *                     using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start;
	listint_t *end;
	listint_t *current;

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
			}
			else
				current = current->next;
		}
		end = current;

		if (!swapped)
			break;

		swapped = 0;
		current = end->prev;

		/* backward pass */
		while (current && current->prev)
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
		start = current ? current->next : *list;
	}
}
