#include "sort.h"

/**
 * merge - Merge two sorted subarrays into one
 * @array: Main array
 * @left: Start index of left subarray
 * @mid: End index of left subarray
 * @right: End index of right subarray
 * @temp: Temporary array
 */
void merge(int *array, int left, int mid, int right, int *temp)
{
    int i, j, k, x;

    i = left;
    j = mid + 1;
    k = left;

    /* Only print merges of arrays with more than one element */
    if (right - left >= 1)
    {
        printf("Merging...\n[left]: ");
        for (x = left; x <= mid; x++)
        {
            if (x > left)
                printf(", ");
            printf("%d", array[x]);
        }

        printf("\n[right]: ");
        for (x = mid + 1; x <= right; x++)
        {
            if (x > mid + 1)
                printf(", ");
            printf("%d", array[x]);
        }
        printf("\n");
    }

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= right)
        temp[k++] = array[j++];

    for (i = left; i <= right; i++)
        array[i] = temp[i];

    if (right - left >= 1)
    {
        printf("[Done]: ");
        for (i = left; i <= right; i++)
        {
            if (i > left)
                printf(", ");
            printf("%d", array[i]);
        }
        printf("\n");
    }
}

/**
 * merge_sort_rec - Recursive top-down merge sort
 * @array: Array to sort
 * @left: Left index
 * @right: Right index
 * @temp: Temporary array
 */
void merge_sort_rec(int *array, int left, int right, int *temp)
{
    int mid;

    if (left >= right)
        return;

    mid = left + (right - left) / 2;

    merge_sort_rec(array, left, mid, temp);
    merge_sort_rec(array, mid + 1, right, temp);

    if (right - left >= 1)
        merge(array, left, mid, right, temp);
}

/**
 * merge_sort - Top-down Merge Sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (!array || size < 2)
        return;

    temp = malloc(sizeof(int) * size);
    if (!temp)
        return;

    merge_sort_rec(array, 0, size - 1, temp);

    free(temp);
}
