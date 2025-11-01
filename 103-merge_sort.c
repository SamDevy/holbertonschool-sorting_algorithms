#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - merge two sorted subarrays into one
 * @array: original array
 * @tmp: temporary array
 * @left: start index of left subarray
 * @mid: end index of left subarray
 * @right: end index of right subarray
 */
void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
    size_t i = left, j = mid + 1, k = left;

    printf("Merging...\n[left]: ");
    for (size_t l = left; l <= mid; l++)
        printf("%d%s", array[l], l < mid ? ", " : "\n");

    printf("[right]: ");
    for (size_t l = mid + 1; l <= right; l++)
        printf("%d%s", array[l], l < right ? ", " : "\n");

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            tmp[k++] = array[i++];
        else
            tmp[k++] = array[j++];
    }
    while (i <= mid)
        tmp[k++] = array[i++];
    while (j <= right)
        tmp[k++] = array[j++];

    for (i = left; i <= right; i++)
        array[i] = tmp[i];

    printf("[Done]: ");
    for (i = left; i <= right; i++)
        printf("%d%s", array[i], i < right ? ", " : "\n");
}

/**
 * merge_sort_recursive - recursive top-down merge sort
 * @array: array to sort
 * @tmp: temporary array
 * @left: left index
 * @right: right index
 */
void merge_sort_recursive(int *array, int *tmp, size_t left, size_t right)
{
    if (left >= right)
        return;

    size_t mid = left + (right - left) / 2;

    merge_sort_recursive(array, tmp, left, mid);
    merge_sort_recursive(array, tmp, mid + 1, right);
    merge(array, tmp, left, mid, right);
}

/**
 * merge_sort - entry point for merge sort
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    int *tmp = malloc(sizeof(int) * size);
    if (!tmp)
        return;

    merge_sort_recursive(array, tmp, 0, size - 1);
    free(tmp);
}
