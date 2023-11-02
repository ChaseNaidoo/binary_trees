#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 *
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
	return (NULL);

	if (first == second)
	return ((binary_tree_t *)first);

	while (first)
	{
	binary_tree_t *tmp = (binary_tree_t *)second;

	while (tmp)
		{
		if (first == tmp)
		return ((binary_tree_t *)first);
		tmp = tmp->parent;
		}
	first = first->parent;
	}
	return (NULL);
}
