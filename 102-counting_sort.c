#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: The array to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
    int *count;
    int *output;
    int max = 0;
    size_t i;

    if (!array || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Allocate memory for counting array */
    count = malloc(sizeof(int) * (max + 1));
    if (!count)
        return;

    for (i = 0; i <= (size_t)max; i++)
        count[i] = 0;

    /* Store the count of each element */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Print the counting array */
    for (i = 0; i <= (size_t)max; i++)
    {
        if (i != 0)
            printf(", ");
        printf("%d", count[i]);
    }
    printf("\n");

    /* Modify count array to store cumulative counts */
    for (i = 1; i <= (size_t)max; i++)
        count[i] += count[i - 1];

    /* Allocate memory for output array */
    output = malloc(sizeof(int) * size);
    if (!output)
    {
        free(count);
        return;
    }

    /* Build the output array */
    for (i = size; i > 0; i--)
        output[count[array[i - 1]]-- - 1] = array[i - 1];

    /* Copy sorted elements back to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count);
    free(output);
}
