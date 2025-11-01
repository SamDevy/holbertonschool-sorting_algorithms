#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swap two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bitonic_merge - Recursively sorts a bitonic sequence in ascending or descending order
 * @array: The array to sort
 * @low: Starting index
 * @cnt: Number of elements
 * @dir: Direction: 1 = ascending, 0 = descending
 * @size: Total size of array (for printing)
 */
void bitonic_merge(int *array, int low, int cnt, int dir, size_t size)
{
    int k, i;

    if (cnt > 1)
    {
        k = cnt / 2;
        for (i = low; i < low + k; i++)
        {
            if ((dir == 1 && array[i] > array[i + k]) ||
                (dir == 0 && array[i] < array[i + k]))
            {
                swap_ints(&array[i], &array[i + k]);
                print_array(array, size);
            }
        }
        bitonic_merge(array, low, k, dir, size);
        bitonic_merge(array, low + k, k, dir, size);
    }
}

/**
 * bitonic_rec - Creates a bitonic sequence and sorts it
 * @array: The array to sort
 * @low: Starting index
 * @cnt: Number of elements
 * @dir: Direction: 1 = ascending, 0 = descending
 * @size: Total size of array (for printing)
 */
void bitonic_rec(int *array, int low, int cnt, int dir, size_t size)
{
    int k;

    if (cnt > 1)
    {
        k = cnt / 2;

        printf("Merging [%d/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + low, k);
        print_array(array + low + k, k);

        bitonic_rec(array, low, k, 1, size);        /* ascending */
        bitonic_rec(array, low + k, k, 0, size);    /* descending */
        bitonic_merge(array, low, cnt, dir, size);

        printf("Result [%d/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + low, cnt);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: The array to sort
 * @size: Number of elements in array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_rec(array, 0, size, 1, size); /* 1 = ascending */
}
