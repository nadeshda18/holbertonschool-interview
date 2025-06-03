#include "binary_trees.h"

/**
 * swap_values - Swaps the values of two nodes.
 * @a: First node.
 * @b: Second node.
 */
void swap_values(heap_t *a, heap_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * get_last_node - Finds the last node in level-order traversal.
 * @root: Pointer to the root of the heap.
 *
 * Return: Pointer to the last node.
 */
heap_t *get_last_node(heap_t *root)
{
    heap_t *queue[1024];
    int front = 0, rear = 0;

    if (!root)
        return (NULL);

    queue[rear++] = root;
    while (front < rear)
    {
        root = queue[front++];
        if (root->left)
            queue[rear++] = root->left;
        if (root->right)
            queue[rear++] = root->right;
    }
    return (root);
}

/**
 * heapify_down - Rebuilds the heap by moving the root down.
 * @root: Pointer to the root of the heap.
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;

    if (root->left && root->left->n > largest->n)
        largest = root->left;
    if (root->right && root->right->n > largest->n)
        largest = root->right;

    if (largest != root)
    {
        swap_values(root, largest);
        heapify_down(largest);
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 *
 * Return: Value stored in the root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    heap_t *last_node, *parent;
    int value;

    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last_node = get_last_node(*root);

    if (last_node == *root)
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    parent = last_node->parent;
    if (parent->left == last_node)
        parent->left = NULL;
    else
        parent->right = NULL;

    (*root)->n = last_node->n;
    free(last_node);

    heapify_down(*root);

    return (value);
}