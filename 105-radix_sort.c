#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - find the maximum number in an array
 * @array: array of integers
 * @size: size of the array
 * Return: maximum number
 */
int get_max(int *array, size_t size)
{
    int max = array[0];

    for (size_t i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/**
 * counting_sort_for_radix - counting sort based on digit
 * @array: array to sort
 * @size: size of the array
 * @exp: current digit exponent (1, 10, 100...)
 */
void counting_sort_for_radix(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    if (!output)
        return;

    int count[10] = {0};

    /* Count occurrences of digits */
    for (size_t i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Change count[i] so that count[i] now contains actual position */
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (ssize_t i = size - 1; i >= 0; i--)
    {
        int digit = (array[i] / exp) % 10;
        output[count[digit] - 1] = array[i];
        count[digit]--;
    }

    /* Copy the output array back to original array */
    for (size_t i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
}

/**
 * radix_sort - LSD Radix Sort
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int max = get_max(array, size);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort_for_radix(array, size, exp);
        print_array(array, size); /* print after each significant digit */
    }
}
