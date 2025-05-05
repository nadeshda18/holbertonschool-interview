#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * using the Advanced Binary Search algorithm
 *
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
size_t mid, i;
int result;

if (array == NULL || size == 0)
return (-1);

printf("Searching in array: ");
for (i = 0; i < size; i++)
{
if (i > 0)
printf(", ");
printf("%d", array[i]);
}
printf("\n");

mid = size / 2;

if (array[mid] == value && (mid == 0 || array[mid - 1] != value))
return (mid);
else if (array[mid] >= value)
return (advanced_binary(array, mid, value));
else
{
result = advanced_binary(array + mid + 1, size - mid - 1, value);
if (result != -1)
return (mid + 1 + result);
return (-1);
}
}
