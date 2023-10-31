#include "binary_trees.h"

/**
 * binary_tree_depth - A function that measures the depth of a node in
 * a binary tree
 * @tree: A pointer to the node to measure the depth
 * Return: Depth of the node
 * If tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	depth = 0;
	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
