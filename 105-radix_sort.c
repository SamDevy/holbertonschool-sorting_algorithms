#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * get_max - finds the maximum value in an array
 * @array: array of integers
 * @size: size of the array
 * Return: maximum integer in the array
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_for_radix - counting sort of array for a given digit
 * @array: array of integers
 * @size: size of the array
 * @exp: current digit exponent (1, 10, 100...)
 */
void counting_sort_for_radix(int *array, size_t size, int exp)
{
	size_t i;
	int *output;
	int count[10];
	int digit;
	size_t j;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < 10; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		digit = (array[i - 1] / exp) % 10;
		output[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}

	for (j = 0; j < size; j++)
		array[j] = output[j];

	free(output);
}

/**
 * radix_sort - sorts an array of integers using LSD Radix Sort
 * @array: array of integers
 * @size: size of the array
 */
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
