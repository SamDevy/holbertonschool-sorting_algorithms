#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Helper functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms */

/**
 * bubble_sort - Sorts an array of integers using Bubble sort
 * @array: The array to sort
 * @size: The number of elements in the array
 */
void bubble_sort(int *array, size_t size);

/**
 * insertion_sort_list - Sorts a doubly linked list using Insertion sort
 * @list: Double pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list);

/**
 * selection_sort - Sorts an array of integers using Selection sort
 * @array: The array to sort
 * @size: The number of elements in the array
 */
void selection_sort(int *array, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: The array to sort
 * @size: The number of elements in the array
 */
void quick_sort(int *array, size_t size);

#endif /* SORT_H */
