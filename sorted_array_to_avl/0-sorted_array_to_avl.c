#include "binary_trees.h"

/**
 * sorted_array_to_avl_helper - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index of the current subarray
 * @end: Ending index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the created subtree, or NULL on failure
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    int mid = (start + end) / 2;
    avl_t *node = malloc(sizeof(avl_t));
    if (!node)
        return (NULL);

    node->n = array[mid];
    node->parent = parent;
    node->left = sorted_array_to_avl_helper(array, start, mid - 1, node);
    node->right = sorted_array_to_avl_helper(array, mid + 1, end, node);

    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (sorted_array_to_avl_helper(array, 0, size - 1, NULL));
}
