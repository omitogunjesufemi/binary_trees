#include "binary_trees.h"

void tree_nodes(const binary_tree_t *tree, size_t *count);

/**
 * binary_tree_nodes - A function that counts the nodes with atleast 1 child
 * @tree: A pointer to the root node of the tree to count the number of nodes
 * Return: Count of nodes with atleast 1 child
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count;

	count = 0;
	if (tree == NULL)
		return (0);
	tree_nodes(tree, &count);
	return (count);
}

/**
 * binary_tree_nodes - A function that counts the nodes with atleast 1 child
 * @tree: A pointer to the root node of the tree to count the number of nodes
 * @count: Count of nodes with alteast 1 child
 */
void tree_nodes(const binary_tree_t *tree, size_t *count)
{
	if (tree == NULL)
		return;

	tree_nodes(tree->left, count);
	tree_nodes(tree->right, count);

	if (tree->left == NULL && tree->right == NULL)
		return;
	else
		(*count)++;
}
