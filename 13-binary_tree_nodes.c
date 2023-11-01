#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaves in a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of leaves in the binary tree, or 0 if tree is NULL
 *
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	if (tree->left || tree->right)
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	return (0);
}
