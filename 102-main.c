#include <stdio.h>
#include "sort.h"

/* Helper to print a test case title */
void print_test_title(const char *title)
{
    printf("\n=== %s ===\n", title);
}

/* Main function testing counting sort on multiple cases */
int main(void)
{
    /* Case 1: 20 elements randomly ordered */
    int array1[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7,
                     33, 12, 65, 44, 5, 27, 88, 10, 56, 41};
    size_t n1 = sizeof(array1) / sizeof(array1[0]);
    print_test_title("Array of 20 elements ordered randomly");
    print_array(array1, n1);
    counting_sort(array1, n1);
    print_array(array1, n1);

    /* Case 2: 20 elements almost sorted */
    int array2[] = {1, 2, 3, 5, 4, 6, 7, 8, 9, 11,
                     10, 12, 13, 14, 15, 17, 16, 18, 20, 19};
    size_t n2 = sizeof(array2) / sizeof(array2[0]);
    print_test_title("Array of 20 elements almost sorted");
    print_array(array2, n2);
    counting_sort(array2, n2);
    print_array(array2, n2);

    /* Case 3: 20 elements in descending order */
    int array3[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
                     10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    size_t n3 = sizeof(array3) / sizeof(array3[0]);
    print_test_title("Array of 20 elements descending order");
    print_array(array3, n3);
    counting_sort(array3, n3);
    print_array(array3, n3);

    /* Case 4: 100 elements randomly ordered */
    int array4[100];
    for (int i = 0; i < 100; i++)
        array4[i] = rand() % 200; /* Random numbers from 0 to 199 */
    size_t n4 = sizeof(array4) / sizeof(array4[0]);
    print_test_title("Array of 100 elements ordered randomly");
    print_array(array4, n4);
    counting_sort(array4, n4);
    print_array(array4, n4);

    /* Case 5: 2 elements disordered */
    int array5[] = {2, 1};
    size_t n5 = sizeof(array5) / sizeof(array5[0]);
    print_test_title("Array of 2 elements disordered");
    print_array(array5, n5);
    counting_sort(array5, n5);
    print_array(array5, n5);

    /* Case 6: 20 elements already sorted */
    int array6[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                     11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    size_t n6 = sizeof(array6) / sizeof(array6[0]);
    print_test_title("Array of 20 elements already sorted");
    print_array(array6, n6);
    counting_sort(array6, n6);
    print_array(array6, n6);

    return 0;
}
