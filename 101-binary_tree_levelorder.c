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
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	return;

	queue_node_t *queue = NULL;
	const binary_tree_t *current;

	queue = malloc(sizeof(queue_node_t));
	if (queue == NULL)
	return;

	queue->node = tree;
	queue->next = NULL;

	while (queue)
	{
	current = queue->node;
	func(current->n);

	if (current->left)
	{
	queue_node_t *left_node = malloc(sizeof(queue_node_t));
	if (left_node == NULL)
	return;
	left_node->node = current->left;
	left_node->next = NULL;
	left_node->next = queue;
	queue = left_node;
	}
	if (current->right)
	{
	queue_node_t *right_node = malloc(sizeof(queue_node_t));
	if (right_node == NULL)
	return;
	right_node->node = current->right;
	right_node->next = NULL;
	right_node->next = queue;
	queue = right_node;
	}
	queue_node_t *temp = queue;
	queue = queue->next;
	free(temp);
	}
}

/**
 * struct queue_node_s - Structure for a queue node
 * @node: Pointer to the binary tree node
 * @next: Pointer to the next node in the queue
 */
struct queue_node_s
{
	const binary_tree_t *node;
	struct queue_node_s *next;
};

typedef struct queue_node_s queue_node_t;
