#include "search_algos.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints the current subarray being searched
 * @array: Pointer to the array
 * @left: Left index of the subarray
 * @right: Right index of the subarray
 *
 * Return: Nothing
 */
void print_array(int *array, int left, int right)
{
int i;

printf("Searching in array: ");
for (i = left; i <= right; i++)
{
if (i > left)
printf(", ");
printf("%d", array[i]);
}
printf("\n");
}

/**
 * recursive_binary - Recursively searches for the first occurrence of a value
 * in a sorted array using a modified binary search
 * @array: Pointer to the array
 * @left: Left boundary index
 * @right: Right boundary index
 * @value: Value to search for
 *
 * Return: Index of first occurrence of value, or -1 if not found
 */
int recursive_binary(int *array, int left, int right, int value)
{
int mid;

if (left > right)
return (-1);

print_array(array, left, right);

mid = left + (right - left) / 2;

if (array[mid] == value)
{
if (mid == left || array[mid - 1] != value)
return (mid);
return (recursive_binary(array, left, mid - 1, value));
}
else if (array[mid] > value)
{
return (recursive_binary(array, left, mid - 1, value));
}
else
{
return (recursive_binary(array, mid + 1, right, value));
}
}

/**
 * advanced_binary - Initiates advanced binary search on a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
if (!array || size == 0)
return (-1);

return (recursive_binary(array, 0, size - 1, value));
}
