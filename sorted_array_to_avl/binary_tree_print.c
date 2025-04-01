#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_tree - Recursive function to print the binary tree
 * @tree: Pointer to the root node of the tree to print
 * @depth: Current depth of the tree
 * @is_left: 1 if the node is a left child, 0 if it is a right child
 * @parent: Pointer to the parent node
 */
static void print_tree(const binary_tree_t *tree, int depth, int is_left, const binary_tree_t *parent)
{
    if (!tree)
        return;

    if (depth > 0)
    {
        for (int i = 0; i < depth - 1; i++)
            printf("        ");
        printf("%s", is_left ? ".-------" : "`-------");
    }

    printf("(%03d)", tree->n);

    if (parent)
        printf(" (parent: %03d)", parent->n);

    printf("\n");

    print_tree(tree->left, depth + 1, 1, tree);
    print_tree(tree->right, depth + 1, 0, tree);
}

/**
 * binary_tree_print - Prints a binary tree in the expected format
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (!tree)
        return;

    print_tree(tree, 0, 0, NULL);
}
