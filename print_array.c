#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers
 * @list: The list to print
 *
 * Return: The number of nodes printed
 */
size_t print_list(const listint_t *list)
{
    size_t i = 0;

    while (list)
    {
        printf("%d", list->n);
        list = list->next;
        i++;
        if (list)
            printf(", ");
    }
    printf("\n");
    return (i);
}
