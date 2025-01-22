#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_size(tree->left) == binary_tree_size(tree->right))
		return (1);

	return (0);
}

/**
 * heapify_up - Restores the max-heap property by swapping nodes up the tree
 * @node: Pointer to the node to heapify
 *
 * Return: Pointer to the node after heapifying
 */
heap_t *heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}

	return (node);
}

/**
 * insert_node - Inserts a node into a binary tree
 * @root: Double pointer to the root node of the tree
 * @node: Pointer to the node to insert
 *
 * Return: Pointer to the inserted node
 */
heap_t *insert_node(heap_t **root, heap_t *node)
{
	heap_t *parent;
	size_t size;
	size_t i;

	if (*root == NULL)
	{
		*root = node;
		return (node);
	}

	size = binary_tree_size(*root);
	parent = *root;

	for (i = 1 << (sizeof(size_t) * 8 - __builtin_clz(size + 1) - 2);
		i > 1;
		i >>= 1)
		parent = (size + 1) & i ? parent->right : parent->left;

	if (parent->left == NULL)
		parent->left = node;
	else
		parent->right = node;

	node->parent = parent;

	return (heapify_up(node));
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	return (insert_node(root, new_node));
}
