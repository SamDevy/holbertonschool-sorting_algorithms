#include "sort.h"

/**
 * swap - Swap two integers in an array
 * @a: First integer pointer
 * @b: Second integer pointer
 */
void swap(int *a, int *b)
{
    int temp = *a;
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
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != root)
    {
        swap(&array[root], &array[largest]);
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
    size_t i;
    int j;

    if (!array || size < 2)
        return;

    /* Build max heap (no printing here) */
    j = (int)(size / 2 - 1);
    for (; j >= 0; j--)
        sift_down(array, size, j);

    /* Extract elements from heap and print after each swap */
    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, i, 0);
    }
}
