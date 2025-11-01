#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Total number of elements in the array
 *
 * Return: The final index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	/* ✅ لا نبدل ولا نطبع إذا كان العنصرين متساويين */
	if (array[i] != array[high])
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts partitions of the array
 * @array: The array to be sorted
 * @low: The starting index
 * @high: The ending index
 * @size: The total number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The number of elements in the array
 *
 * Description: Uses the Lomuto partition scheme. Prints the array
 *              after each swap of two distinct elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
