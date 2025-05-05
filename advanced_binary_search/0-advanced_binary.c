#include "search_algos.h"
#include <stdio.h>

/**
 * advanced_binary - Entry point to search for first occurrence of value
 * @array: Pointer to array
 * @size: Size of array
 * @value: Value to search
 * Return: Index or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
if (array == NULL || size == 0)
return (-1);

return (recursive_binary(array, 0, (int)size - 1, value));
}

/**
 * recursive_binary - Recursively searches for first occurrence
 * @array: Pointer to full array
 * @left: Left index
 * @right: Right index
 * @value: Target value
 * Return: Index or -1
 */
int recursive_binary(int *array, int left, int right, int value)
{
int i, mid;

if (left > right)
return (-1);

printf("Searching in array: ");
for (i = left; i <= right; i++)
{
if (i > left)
printf(", ");
printf("%d", array[i]);
}
printf("\n");

mid = left + (right - left) / 2;

if (array[mid] == value)
{
if (mid == left || array[mid - 1] != value)
return (mid);
return (recursive_binary(array, left, mid, value));
}
else if (array[mid] > value)
return (recursive_binary(array, left, mid - 1, value));
else
return (recursive_binary(array, mid + 1, right, value));
}
