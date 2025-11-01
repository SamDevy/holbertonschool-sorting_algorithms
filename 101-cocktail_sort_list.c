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
 * forward_pass - performs a forward pass of cocktail shaker sort
 * @list: pointer to the head of the list
 * @start: starting node
 * @end: ending node
 * Return: pointer to the last node after pass
 */
listint_t *forward_pass(listint_t **list, listint_t *start, listint_t *end)
{
	listint_t *current;

	current = start;
	while (current->next != end)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			print_list(*list);
		}
		else
			current = current->next;
	}
	return (current);
}

/**
 * backward_pass - performs a backward pass of cocktail shaker sort
 * @list: pointer to the head of the list
 * @start: starting node
 * @end: ending node
 * Return: pointer to the first node after pass
 */
listint_t *backward_pass(listint_t **list, listint_t *start, listint_t *end)
{
	listint_t *current;

	current = end;
	while (current && current->prev != start->prev)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
		}
		else
			current = current->prev;
	}
	return (current);
}

/**
 * cocktail_sort_list - sorts a doubly linked list in ascending order
 *                     using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start;
	listint_t *end;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;

	while (1)
	{
		end = forward_pass(list, start, end);
		if (!start || start == end)
			break;

		start = backward_pass(list, start, end);
		if (!end || start == end)
			break;
	}
}
