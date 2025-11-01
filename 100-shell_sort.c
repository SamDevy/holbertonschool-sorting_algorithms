#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order
 *               using the Shell sort algorithm (Knuth sequence)
 * @array: Pointer to the array
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;
    int temp;

    if (!array || size < 2)
        return;

    /* Generate initial Knuth sequence gap */
    for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
        ; /* nothing, just compute initial gap */

    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }

        print_array(array, size); /* print array after each gap reduction */

        gap /= 3; /* move to next smaller gap */
    }
}
