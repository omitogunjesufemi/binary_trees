#include "binary_trees.h"

size_t tree_height_size(const binary_tree_t *tree, size_t *size);
size_t exponential(size_t base, size_t power);

/**
 * bianry_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if perfect, and 0 if otherwise
 * If tree is NULL, function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t tree_size, height, expected_size;

	tree_size = 0;
	height = tree_height_size(tree, &tree_size);
	expected_size = exponential(2, height + 1) - 1;
	if (expected_size == tree_size)
		return (1);
	return (0);
}

/**
 * tree_height_size - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @size: Number of nodes in the tree
 * Return: Height of tree
 */
size_t tree_height_size(const binary_tree_t *tree, size_t *size)
{
	int l_height, r_height;
	size_t max;

	if (tree == NULL)
		return (-1);
	l_height = tree_height_size(tree->left, size);
	r_height = tree_height_size(tree->right, size);

	if (l_height > r_height)
		max = l_height;
	else
		max = r_height;
	(*size)++;
	return (max + 1);
}

/**
 * exponential - A function that raise a base to a particular power
 * @base: The base digit
 * @power: The power digit
 * Return: exponential result
 */
size_t exponential(size_t base, size_t power)
{
	size_t result;

	result = base;
	while (power != 1)
	{
		result *= base;
		power--;
	}
	return (result);
}
