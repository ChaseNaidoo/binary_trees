#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 *
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to uncle node, NULL if node is NULL or there is no uncle
 *
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	return (NULL);

	if (node->parent == node->parent->parent->left)
	return (node->parent->parent->right);
	else
	return (node->parent->parent->left);
}
