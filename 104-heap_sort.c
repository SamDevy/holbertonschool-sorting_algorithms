#include "sort.h"

/**
 * swap - Swap two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - Maintains the max-heap property for a subtree rooted at index i
 * @array: The array to heapify
 * @size: Size of the heap
 * @i: Root index
 * @n: Total size of the array (for printing)
 */
void heapify(int *array, size_t size, size_t i, size_t n)
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
        print_array(array, n);
        heapify(array, size, largest, n);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    size_t i;

    /* Build max heap */
    for (i = size / 2; i > 0; i--)
        heapify(array, size, i - 1, size);

    /* Extract elements from heap */
    for (i = size; i > 1; i--)
    {
        swap(&array[0], &array[i - 1]);
        print_array(array, size);
        heapify(array, i - 1, 0, size);
    }
}
