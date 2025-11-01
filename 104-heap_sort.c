#include "sort.h"

/**
 * swap - Swap two integers in an array
 * @a: First integer pointer
 * @b: Second integer pointer
 */
void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * sift_down - Maintains the max-heap property for a subtree
 * @array: The array representing the heap
 * @size: Size of the heap
 * @root: Root index of the subtree
 */
void sift_down(int *array, size_t size, size_t root)
{
    size_t largest, left, right;

    largest = root;
    left = 2 * root + 1;
    right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap(&array[root], &array[largest]);
        print_array(array, size); /* Print after every swap */
        sift_down(array, size, largest);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int start;
    size_t i;

    if (!array || size < 2)
        return;

    /* Build max heap */
    start = (int)(size / 2 - 1);
    for (; start >= 0; start--)
        sift_down(array, size, start);

    /* Extract elements from heap */
    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size); /* Print after swap */
        sift_down(array, i, 0);
    }
}
