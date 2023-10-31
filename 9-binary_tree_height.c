#include "binary_trees.h"

int max_num(int a, int b);
size_t tree_height(const binary_tree_t *tree);

/**
 * binary_tree_height - A function that measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: Measured height of tree
 * If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_height(tree));
}

/**
 * tree_height - A function that recursively traverse through the tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: Measured height of sub-tree
 * If tree is NULL, return 0
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t lx, rx;

	if (tree == NULL)
		return (-1);

	lx = tree_height(tree->left);
	rx = tree_height(tree->right);
	return (max_num(lx, rx) + 1);
}


/**
 * max_num - Returns the largest number
 * @a: First digit
 * @b: Second digit
 * Return: Max number
 */
int max_num(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
