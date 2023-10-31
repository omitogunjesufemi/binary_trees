#include "binary_trees.h"

void tree_leaves(const binary_tree_t *tree, size_t *count);

/**
 * binary_tree_leaves - A function that counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of leaves
 * Return: Number of leaves in a binary tree
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count;

	count = 0;
	if (tree == NULL)
		return (0);
	tree_leaves(tree, &count);
	return (count);
}

/**
 * tree_leaves - A recursive function that counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of leaves
 * Return: Number of leaves in a binary tree
 */
void tree_leaves(const binary_tree_t *tree, size_t *count)
{
	if (tree == NULL)
		return;

	tree_leaves(tree->left, count);
	tree_leaves(tree->right, count);
	if (tree->left == NULL && tree->right == NULL)
		(*count)++;
}
