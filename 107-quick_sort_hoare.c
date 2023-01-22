#include "sort.h"

/**
 * swap - change position between two position of an array and print the array
 * @array: array to sort
 * @first: lowest position
 * @last: highest position
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (size < 2)
        return;
    int pivot = array[size - 1];
    int i = -1, j = size;
    while (1)
    {
        do
            i++;
        while (array[i] < pivot);
        do
            j--;
        while (array[j] > pivot);
        if (i >= j)
            break;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        for (int k = 0; k < size; k++)
            printf("%d ", array[k]);
        printf("\n");
    }
    quick_sort_hoare(array, j);
    quick_sort_hoare(array + j, size - j);
}
