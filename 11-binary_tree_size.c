#include "binary_trees.h"

/**
 * binary_tree_size - A function that measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size
 * Return: Depth of a node
 * If tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_size(tree->left);
	r_height = binary_tree_size(tree->right);

	return (l_height + r_height + 1);
}
