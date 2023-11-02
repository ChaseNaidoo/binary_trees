#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal of a binary tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to the function to call for each node
 *
 * Return: (no return)
 *
 */
/**
 * binary_tree_levelorder - Perform level-order traversal on a binary tree.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
  int height = binary_tree_height(tree);
  int level;

  if (tree == NULL || func == NULL)
    return;

  for (level = 1; level <= height + 1; level++)
    levelorder_util(tree, func, level);
}

/**
 * levelorder_util - Helper function for level-order traversal.
 * @tree: A pointer to the root node of the current subtree.
 * @func: A pointer to a function to call for each node.
 * @level: The current level to visit.
 */
void levelorder_util(const binary_tree_t *tree, void (*func)(int), int level)
{
  if (tree == NULL)
    return;

  if (level == 1)
    func(tree->n);
  else if (level > 1)
    {
      levelorder_util(tree->left, func, level - 1);
      levelorder_util(tree->right, func, level - 1);
    }
}

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: The height of the tree, or -1 if the tree is NULL.
 */
int binary_tree_height(const binary_tree_t *tree)
{
  if (tree == NULL)
    return -1;

  int left_height = binary_tree_height(tree->left);
  int right_height = binary_tree_height(tree->right);

  return (left_height > right_height ? left_height : right_height) + 1;
}
