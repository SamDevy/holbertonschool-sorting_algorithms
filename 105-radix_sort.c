#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/* Find maximum value in the array */
int get_max(int *array, size_t size)
{
    int max;
    size_t i;

    max = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/* Counting sort based on current digit */
void counting_sort_for_radix(int *array, size_t size, int exp)
{
    int *output;
    int count[10];
    size_t i;
    int digit;

    /* Allocate memory for output array */
    output = malloc(sizeof(int) * size);
    if (!output)
        return;

    /* Initialize count array to 0 */
    for (i = 0; i < 10; i++)
        count[i] = 0;

    /* Count occurrences of digits */
    for (i = 0; i < size; i++)
    {
        digit = (array[i] / exp) % 10;
        count[digit]++;
    }

    /* Update count[i] to store actual positions */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array (traverse from end) */
    for (i = size; i > 0; i--)
    {
        digit = (array[i - 1] / exp) % 10;
        output[count[digit] - 1] = array[i - 1];
        count[digit]--;
    }

    /* Copy output back to original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/* LSD Radix Sort */
void radix_sort(int *array, size_t size)
{
    int max;
    int exp;

    if (!array || size < 2)
        return;

    max = get_max(array, size);
    exp = 1;

    while (max / exp > 0)
    {
        counting_sort_for_radix(array, size, exp);
        print_array(array, size);
        exp *= 10;
    }
}
