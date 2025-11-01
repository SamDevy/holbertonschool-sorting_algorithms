#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int left, int mid, int right, int *temp)
{
    int i, j, k, x;

    i = left;
    j = mid + 1;
    k = left;

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

    printf("[Done]: ");
    for (i = left; i <= right; i++)
    {
        if (i > left)
            printf(", ");
        printf("%d", array[i]);
    }
    printf("\n");
}

void merge_sort_rec(int *array, int left, int right, int *temp)
{
    int mid;

    if (left >= right)
        return;

    mid = left + (right - left) / 2;

    /* Sort left first */
    merge_sort_rec(array, left, mid, temp);
    /* Sort right second */
    merge_sort_rec(array, mid + 1, right, temp);
    /* Merge left and right */
    merge(array, left, mid, right, temp);
}

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
