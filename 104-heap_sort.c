#include "sort.h"
#include <stdio.h>

/**
 * swap - Swap two elements in an array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Maintains the heap property for a subtree rooted at index i
 * @array: The array to heapify
 * @size: Size of the heap
 * @i: Index of the root of the subtree
 */
void heapify(int *array, size_t size, size_t i)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        print_array(array, size);
        heapify(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to sort
 * @size: Number of elements in array
 */
void heap_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    /* Build max heap */
    for (int i = (int)(size / 2 - 1); i >= 0; i--)
        heapify(array, size, i);

    /* Extract elements one by one */
    for (size_t i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0);
    }
}
